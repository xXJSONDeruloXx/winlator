package com.winlator.xserver;

import com.winlator.xconnector.ConnectedClient;
import com.winlator.xconnector.RequestHandler;
import com.winlator.xconnector.XInputStream;
import com.winlator.xconnector.XOutputStream;
import com.winlator.xconnector.XStreamLock;
import com.winlator.xserver.XServer;
import com.winlator.xserver.errors.XRequestError;
import com.winlator.xserver.extensions.Extension;
import com.winlator.xserver.requests.AtomRequests;
import com.winlator.xserver.requests.CursorRequests;
import com.winlator.xserver.requests.DrawRequests;
import com.winlator.xserver.requests.ExtensionRequests;
import com.winlator.xserver.requests.FontRequests;
import com.winlator.xserver.requests.GrabRequests;
import com.winlator.xserver.requests.GraphicsContextRequests;
import com.winlator.xserver.requests.KeyboardRequests;
import com.winlator.xserver.requests.PixmapRequests;
import com.winlator.xserver.requests.SelectionRequests;
import com.winlator.xserver.requests.WindowRequests;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.Objects;

/* JADX INFO: loaded from: classes.dex */
public class XClientRequestHandler implements RequestHandler {
    @Override // com.winlator.xconnector.RequestHandler
    public boolean handleRequest(ConnectedClient client) throws IOException {
        XClient xClient = (XClient) client;
        XInputStream inputStream = client.getInputStream();
        XOutputStream outputStream = client.getOutputStream();
        if (xClient.isAuthenticated()) {
            return handleNormalRequest(xClient, inputStream, outputStream);
        }
        return handleAuthRequest(xClient, inputStream, outputStream);
    }

    private void sendServerInformation(XClient client, XOutputStream outputStream) throws IOException {
        int i;
        short vendorNameLength = (short) "Elbrus Technologies, LLC".length();
        byte pixmapFormatCount = (byte) client.xServer.pixmapManager.supportedPixmapFormats.length;
        XStreamLock lock = outputStream.lock();
        try {
            outputStream.writeByte((byte) 1);
            outputStream.writeByte((byte) 0);
            outputStream.writeShort((short) 11);
            outputStream.writeShort((short) 0);
            outputStream.writeShort((short) 0);
            outputStream.writeInt(1);
            outputStream.writeInt(client.resourceIDBase.intValue());
            outputStream.writeInt(client.xServer.resourceIDs.idMask);
            outputStream.writeInt(256);
            outputStream.writeShort(vendorNameLength);
            outputStream.writeShort((short) -1);
            outputStream.writeByte((byte) 1);
            outputStream.writeByte(pixmapFormatCount);
            outputStream.writeByte((byte) 0);
            outputStream.writeByte((byte) 0);
            outputStream.writeByte((byte) 32);
            outputStream.writeByte((byte) 32);
            outputStream.writeByte((byte) 8);
            outputStream.writeByte((byte) -1);
            outputStream.writeInt(0);
            outputStream.writeString8("Elbrus Technologies, LLC");
            for (PixmapFormat pixmapFormat : client.xServer.pixmapManager.supportedPixmapFormats) {
                outputStream.writeByte(pixmapFormat.depth);
                outputStream.writeByte(pixmapFormat.bitsPerPixel);
                outputStream.writeByte(pixmapFormat.scanlinePad);
                outputStream.writePad(5);
            }
            Visual rootVisual = client.xServer.windowManager.rootWindow.getContent().visual;
            outputStream.writeInt(client.xServer.windowManager.rootWindow.id);
            outputStream.writeInt(0);
            outputStream.writeInt(16777215);
            outputStream.writeInt(0);
            outputStream.writeInt(client.xServer.windowManager.rootWindow.getAllEventMasks().getBits());
            outputStream.writeShort(client.xServer.screenInfo.width);
            outputStream.writeShort(client.xServer.screenInfo.height);
            outputStream.writeShort(client.xServer.screenInfo.getWidthInMillimeters());
            outputStream.writeShort(client.xServer.screenInfo.getHeightInMillimeters());
            outputStream.writeShort((short) 1);
            outputStream.writeShort((short) 1);
            outputStream.writeInt(rootVisual.id);
            outputStream.writeByte((byte) 0);
            outputStream.writeByte((byte) 0);
            outputStream.writeByte(rootVisual.depth);
            outputStream.writeByte((byte) client.xServer.pixmapManager.supportedVisuals.length);
            for (Visual visual : client.xServer.pixmapManager.supportedVisuals) {
                outputStream.writeByte(visual.depth);
                outputStream.writeByte((byte) 0);
                if (visual.displayable) {
                    i = 1;
                } else {
                    i = 0;
                }
                outputStream.writeShort((short) i);
                outputStream.writeInt(0);
                if (visual.displayable) {
                    outputStream.writeInt(visual.id);
                    outputStream.writeByte((byte) visual.type.ordinal());
                    outputStream.writeByte(visual.bitsPerRGBValue);
                    Objects.requireNonNull(visual);
                    outputStream.writeShort((short) 256);
                    outputStream.writeInt(visual.redMask);
                    outputStream.writeInt(visual.greenMask);
                    outputStream.writeInt(visual.blueMask);
                    outputStream.writeInt(0);
                }
            }
            short additionalDataLength = (short) ((outputStream.length() - 8) / 4);
            outputStream.writeAt(6, ByteBuffer.allocate(2).order(ByteOrder.LITTLE_ENDIAN).putShort(additionalDataLength).array());
            if (lock != null) {
                lock.close();
            }
        } catch (Throwable th) {
            if (lock != null) {
                try {
                    lock.close();
                } catch (Throwable th2) {
                    // suppressed
                }
            }
            throw th;
        }
    }

    private boolean handleAuthRequest(XClient client, XInputStream inputStream, XOutputStream outputStream) throws IOException {
        if (inputStream.available() < 12) {
            return false;
        }
        inputStream.skip(2);
        short majorVersion = inputStream.readShort();
        if (majorVersion != 11) {
            throw new UnsupportedOperationException("Unsupported major X protocol version " + ((int) majorVersion) + ".");
        }
        inputStream.skip(2);
        short nameLength = inputStream.readShort();
        short dataLength = inputStream.readShort();
        inputStream.skip(2);
        if (nameLength > 0) {
            inputStream.readString8(nameLength);
        }
        if (dataLength > 0) {
            inputStream.readString8(dataLength);
        }
        XLock lock = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER);
        try {
            sendServerInformation(client, outputStream);
            if (lock != null) {
                lock.close();
            }
            client.setAuthenticated(true);
            return true;
        } catch (Throwable th) {
            if (lock != null) {
                try {
                    lock.close();
                } catch (Throwable th2) {
                    // suppressed
                }
            }
            throw th;
        }
    }

    private boolean handleNormalRequest(XClient client, XInputStream inputStream, XOutputStream outputStream) throws IOException {
        int requestLength;
        XLock lock;
        XLock lock2;
        if (inputStream.available() < 4) {
            return false;
        }
        byte opcode = inputStream.readByte();
        byte requestData = inputStream.readByte();
        int requestLength2 = inputStream.readUnsignedShort();
        if (requestLength2 != 0) {
            requestLength = (requestLength2 * 4) - 4;
        } else {
            if (inputStream.available() < 4) {
                return false;
            }
            requestLength = (inputStream.readInt() * 4) - 8;
        }
        if (inputStream.available() < requestLength) {
            return false;
        }
        client.generateSequenceNumber();
        client.setRequestData(requestData);
        client.setRequestLength(requestLength);
        try {
            if (opcode < 0) {
                Extension extension = client.xServer.getExtension(opcode);
                if (extension != null) {
                    extension.handleRequest(client, inputStream, outputStream);
                }
            } else {
                switch (opcode) {
                    case 1:
                        XLock lock3 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.DRAWABLE_MANAGER, XServer.Lockable.INPUT_DEVICE, XServer.Lockable.CURSOR_MANAGER);
                        try {
                            WindowRequests.createWindow(client, inputStream, outputStream);
                            if (lock3 != null) {
                                lock3.close();
                            }
                        } finally {
                            if (lock3 != null) {
                                try {
                                    lock3.close();
                                } catch (Throwable th) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 2:
                        XLock lock4 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.CURSOR_MANAGER);
                        try {
                            WindowRequests.changeWindowAttributes(client, inputStream, outputStream);
                            if (lock4 != null) {
                                lock4.close();
                            }
                        } finally {
                            if (lock4 != null) {
                                try {
                                    lock4.close();
                                } catch (Throwable th2) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 3:
                        XLock lock5 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER);
                        try {
                            WindowRequests.getWindowAttributes(client, inputStream, outputStream);
                            if (lock5 != null) {
                                lock5.close();
                            }
                        } finally {
                            if (lock5 != null) {
                                try {
                                    lock5.close();
                                } catch (Throwable th3) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 4:
                        XLock lock6 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.DRAWABLE_MANAGER, XServer.Lockable.INPUT_DEVICE);
                        try {
                            WindowRequests.destroyWindow(client, inputStream, outputStream);
                            if (lock6 != null) {
                                lock6.close();
                            }
                        } finally {
                            if (lock6 != null) {
                                try {
                                    lock6.close();
                                } catch (Throwable th4) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 5:
                        lock = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.DRAWABLE_MANAGER, XServer.Lockable.INPUT_DEVICE);
                        try {
                            WindowRequests.destroySubWindows(client, inputStream, outputStream);
                            if (lock != null) {
                                lock.close();
                            }
                        } finally {
                            if (lock != null) {
                                try {
                                    lock.close();
                                } catch (Throwable th5) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 7:
                        XLock lock7 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER);
                        try {
                            WindowRequests.reparentWindow(client, inputStream, outputStream);
                            if (lock7 != null) {
                                lock7.close();
                            }
                        } finally {
                            if (lock7 != null) {
                                try {
                                    lock7.close();
                                } catch (Throwable th6) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 8:
                        XLock lock8 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.INPUT_DEVICE);
                        try {
                            WindowRequests.mapWindow(client, inputStream, outputStream);
                            if (lock8 != null) {
                                lock8.close();
                            }
                        } finally {
                            if (lock8 != null) {
                                try {
                                    lock8.close();
                                } catch (Throwable th7) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 9:
                        XLock lock9 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.INPUT_DEVICE);
                        try {
                            WindowRequests.mapSubWindows(client, inputStream, outputStream);
                            if (lock9 != null) {
                                lock9.close();
                            }
                        } finally {
                            if (lock9 != null) {
                                try {
                                    lock9.close();
                                } catch (Throwable th8) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 10:
                        XLock lock10 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.INPUT_DEVICE);
                        try {
                            WindowRequests.unmapWindow(client, inputStream, outputStream);
                            if (lock10 != null) {
                                lock10.close();
                            }
                        } finally {
                            if (lock10 != null) {
                                try {
                                    lock10.close();
                                } catch (Throwable th9) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 12:
                        XLock lock11 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.INPUT_DEVICE);
                        try {
                            WindowRequests.configureWindow(client, inputStream, outputStream);
                            if (lock11 != null) {
                                lock11.close();
                            }
                        } finally {
                            if (lock11 != null) {
                                try {
                                    lock11.close();
                                } catch (Throwable th10) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 14:
                        XLock lock12 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.DRAWABLE_MANAGER);
                        try {
                            WindowRequests.getGeometry(client, inputStream, outputStream);
                            if (lock12 != null) {
                                lock12.close();
                            }
                        } finally {
                            if (lock12 != null) {
                                try {
                                    lock12.close();
                                } catch (Throwable th11) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 15:
                        XLock lock13 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER);
                        try {
                            WindowRequests.queryTree(client, inputStream, outputStream);
                            if (lock13 != null) {
                                lock13.close();
                            }
                        } finally {
                            if (lock13 != null) {
                                try {
                                    lock13.close();
                                } catch (Throwable th12) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 16:
                        AtomRequests.internAtom(client, inputStream, outputStream);
                        break;
                    case 17:
                        AtomRequests.getAtomName(client, inputStream, outputStream);
                        break;
                    case 18:
                        XLock lock14 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER);
                        try {
                            WindowRequests.changeProperty(client, inputStream, outputStream);
                            if (lock14 != null) {
                                lock14.close();
                            }
                        } finally {
                            if (lock14 != null) {
                                try {
                                    lock14.close();
                                } catch (Throwable th13) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 19:
                        XLock lock15 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER);
                        try {
                            WindowRequests.deleteProperty(client, inputStream, outputStream);
                            if (lock15 != null) {
                                lock15.close();
                            }
                        } finally {
                            if (lock15 != null) {
                                try {
                                    lock15.close();
                                } catch (Throwable th14) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 20:
                        lock2 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER);
                        try {
                            WindowRequests.getProperty(client, inputStream, outputStream);
                            if (lock2 != null) {
                                lock2.close();
                            }
                        } finally {
                            if (lock2 != null) {
                                try {
                                    lock2.close();
                                } catch (Throwable th15) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 22:
                        XLock lock16 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER);
                        try {
                            SelectionRequests.setSelectionOwner(client, inputStream, outputStream);
                            if (lock16 != null) {
                                lock16.close();
                            }
                        } finally {
                            if (lock16 != null) {
                                try {
                                    lock16.close();
                                } catch (Throwable th16) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 23:
                        XLock lock17 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER);
                        try {
                            SelectionRequests.getSelectionOwner(client, inputStream, outputStream);
                            if (lock17 != null) {
                                lock17.close();
                            }
                        } finally {
                            if (lock17 != null) {
                                try {
                                    lock17.close();
                                } catch (Throwable th17) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 25:
                        XLock lock18 = client.xServer.lockAll();
                        try {
                            WindowRequests.sendEvent(client, inputStream, outputStream);
                            if (lock18 != null) {
                                lock18.close();
                            }
                        } finally {
                            if (lock18 != null) {
                                try {
                                    lock18.close();
                                } catch (Throwable th18) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 26:
                        XLock lock19 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.INPUT_DEVICE, XServer.Lockable.CURSOR_MANAGER);
                        try {
                            GrabRequests.grabPointer(client, inputStream, outputStream);
                            if (lock19 != null) {
                                lock19.close();
                            }
                        } finally {
                            if (lock19 != null) {
                                try {
                                    lock19.close();
                                } catch (Throwable th19) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 27:
                        XLock lock20 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.INPUT_DEVICE);
                        try {
                            GrabRequests.ungrabPointer(client, inputStream, outputStream);
                            if (lock20 != null) {
                                lock20.close();
                            }
                        } finally {
                            if (lock20 != null) {
                                try {
                                    lock20.close();
                                } catch (Throwable th20) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 38:
                        XLock lock21 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.INPUT_DEVICE);
                        try {
                            WindowRequests.queryPointer(client, inputStream, outputStream);
                            if (lock21 != null) {
                                lock21.close();
                            }
                        } finally {
                            if (lock21 != null) {
                                try {
                                    lock21.close();
                                } catch (Throwable th21) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 40:
                        XLock lock22 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER);
                        try {
                            WindowRequests.translateCoordinates(client, inputStream, outputStream);
                            if (lock22 != null) {
                                lock22.close();
                            }
                        } finally {
                            if (lock22 != null) {
                                try {
                                    lock22.close();
                                } catch (Throwable th22) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 41:
                        XLock lock23 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.INPUT_DEVICE);
                        try {
                            WindowRequests.warpPointer(client, inputStream, outputStream);
                            if (lock23 != null) {
                                lock23.close();
                            }
                        } finally {
                            if (lock23 != null) {
                                try {
                                    lock23.close();
                                } catch (Throwable th23) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 42:
                        XLock lock24 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER);
                        try {
                            WindowRequests.setInputFocus(client, inputStream, outputStream);
                            if (lock24 != null) {
                                lock24.close();
                            }
                        } finally {
                            if (lock24 != null) {
                                try {
                                    lock24.close();
                                } catch (Throwable th24) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 43:
                        XLock lock25 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER);
                        try {
                            WindowRequests.getInputFocus(client, inputStream, outputStream);
                            if (lock25 != null) {
                                lock25.close();
                            }
                        } finally {
                            if (lock25 != null) {
                                try {
                                    lock25.close();
                                } catch (Throwable th25) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 45:
                        FontRequests.openFont(client, inputStream, outputStream);
                        break;
                    case 49:
                        FontRequests.listFonts(client, inputStream, outputStream);
                        break;
                    case 53:
                        XLock lock26 = client.xServer.lock(XServer.Lockable.PIXMAP_MANAGER, XServer.Lockable.DRAWABLE_MANAGER);
                        try {
                            PixmapRequests.createPixmap(client, inputStream, outputStream);
                            if (lock26 != null) {
                                lock26.close();
                            }
                        } finally {
                            if (lock26 != null) {
                                try {
                                    lock26.close();
                                } catch (Throwable th26) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 54:
                        XLock lock27 = client.xServer.lock(XServer.Lockable.PIXMAP_MANAGER, XServer.Lockable.DRAWABLE_MANAGER);
                        try {
                            PixmapRequests.freePixmap(client, inputStream, outputStream);
                            if (lock27 != null) {
                                lock27.close();
                            }
                        } finally {
                            if (lock27 != null) {
                                try {
                                    lock27.close();
                                } catch (Throwable th27) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 55:
                        XLock lock28 = client.xServer.lock(XServer.Lockable.PIXMAP_MANAGER, XServer.Lockable.DRAWABLE_MANAGER, XServer.Lockable.GRAPHIC_CONTEXT_MANAGER);
                        try {
                            GraphicsContextRequests.createGC(client, inputStream, outputStream);
                            if (lock28 != null) {
                                lock28.close();
                            }
                        } finally {
                            if (lock28 != null) {
                                try {
                                    lock28.close();
                                } catch (Throwable th28) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 56:
                        XLock lock29 = client.xServer.lock(XServer.Lockable.PIXMAP_MANAGER, XServer.Lockable.DRAWABLE_MANAGER, XServer.Lockable.GRAPHIC_CONTEXT_MANAGER);
                        try {
                            GraphicsContextRequests.changeGC(client, inputStream, outputStream);
                            if (lock29 != null) {
                                lock29.close();
                            }
                        } finally {
                            if (lock29 != null) {
                                try {
                                    lock29.close();
                                } catch (Throwable th29) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 58:
                        client.skipRequest();
                        break;
                    case 59:
                        client.skipRequest();
                        break;
                    case 60:
                        XLock lock30 = client.xServer.lock(XServer.Lockable.GRAPHIC_CONTEXT_MANAGER);
                        try {
                            GraphicsContextRequests.freeGC(client, inputStream, outputStream);
                            if (lock30 != null) {
                                lock30.close();
                            }
                        } finally {
                            if (lock30 != null) {
                                try {
                                    lock30.close();
                                } catch (Throwable th30) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 61:
                        XLock lock31 = client.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.DRAWABLE_MANAGER);
                        try {
                            DrawRequests.clearArea(client, inputStream, outputStream);
                            if (lock31 != null) {
                                lock31.close();
                            }
                        } finally {
                            if (lock31 != null) {
                                try {
                                    lock31.close();
                                } catch (Throwable th31) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 62:
                        XLock lock32 = client.xServer.lock(XServer.Lockable.DRAWABLE_MANAGER, XServer.Lockable.GRAPHIC_CONTEXT_MANAGER);
                        try {
                            DrawRequests.copyArea(client, inputStream, outputStream);
                            if (lock32 != null) {
                                lock32.close();
                            }
                        } finally {
                            if (lock32 != null) {
                                try {
                                    lock32.close();
                                } catch (Throwable th32) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 65:
                        XLock lock33 = client.xServer.lock(XServer.Lockable.DRAWABLE_MANAGER, XServer.Lockable.GRAPHIC_CONTEXT_MANAGER);
                        try {
                            DrawRequests.polyLine(client, inputStream, outputStream);
                            if (lock33 != null) {
                                lock33.close();
                            }
                        } finally {
                            if (lock33 != null) {
                                try {
                                    lock33.close();
                                } catch (Throwable th33) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 66:
                        client.skipRequest();
                        break;
                    case 67:
                        client.skipRequest();
                        break;
                    case 70:
                        XLock lock34 = client.xServer.lock(XServer.Lockable.DRAWABLE_MANAGER, XServer.Lockable.GRAPHIC_CONTEXT_MANAGER);
                        try {
                            DrawRequests.polyFillRectangle(client, inputStream, outputStream);
                            if (lock34 != null) {
                                lock34.close();
                            }
                        } finally {
                            if (lock34 != null) {
                                try {
                                    lock34.close();
                                } catch (Throwable th34) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 72:
                        XLock lock35 = client.xServer.lock(XServer.Lockable.DRAWABLE_MANAGER, XServer.Lockable.GRAPHIC_CONTEXT_MANAGER);
                        try {
                            DrawRequests.putImage(client, inputStream, outputStream);
                            if (lock35 != null) {
                                lock35.close();
                            }
                        } finally {
                            if (lock35 != null) {
                                try {
                                    lock35.close();
                                } catch (Throwable th35) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 73:
                        XLock lock36 = client.xServer.lock(XServer.Lockable.PIXMAP_MANAGER, XServer.Lockable.DRAWABLE_MANAGER);
                        try {
                            DrawRequests.getImage(client, inputStream, outputStream);
                            if (lock36 != null) {
                                lock36.close();
                            }
                        } finally {
                            if (lock36 != null) {
                                try {
                                    lock36.close();
                                } catch (Throwable th36) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 78:
                        client.skipRequest();
                        break;
                    case 79:
                        client.skipRequest();
                        break;
                    case 93:
                        XLock lock37 = client.xServer.lock(XServer.Lockable.PIXMAP_MANAGER, XServer.Lockable.DRAWABLE_MANAGER, XServer.Lockable.CURSOR_MANAGER);
                        try {
                            CursorRequests.createCursor(client, inputStream, outputStream);
                            if (lock37 != null) {
                                lock37.close();
                            }
                        } finally {
                            if (lock37 != null) {
                                try {
                                    lock37.close();
                                } catch (Throwable th37) {
                                    // suppressed
                                }
                                break;
                            }
                        }
                        break;
                    case 94:
                        client.skipRequest();
                        break;
                    case 95:
                        lock = client.xServer.lock(XServer.Lockable.PIXMAP_MANAGER, XServer.Lockable.DRAWABLE_MANAGER, XServer.Lockable.CURSOR_MANAGER);
                        try {
                            CursorRequests.freeCursor(client, inputStream, outputStream);
                            if (lock != null) {
                                lock.close();
                            }
                        } finally {
                            if (lock != null) {
                                try {
                                    break;
                                } catch (Throwable th52) {
                                }
                            }
                        }
                        break;
                    case 98:
                        ExtensionRequests.queryExtension(client, inputStream, outputStream);
                        break;
                    case 101:
                        lock2 = client.xServer.lock(XServer.Lockable.INPUT_DEVICE);
                        try {
                            KeyboardRequests.getKeyboardMapping(client, inputStream, outputStream);
                            if (lock2 != null) {
                                lock2.close();
                            }
                        } finally {
                            if (lock2 != null) {
                                try {
                                    break;
                                } catch (Throwable th152) {
                                }
                            }
                        }
                        break;
                    case 104:
                        client.skipRequest();
                        break;
                    case 107:
                        client.skipRequest();
                        break;
                    case 108:
                        WindowRequests.getScreenSaver(client, inputStream, outputStream);
                        break;
                    case 115:
                        client.skipRequest();
                        break;
                    case 117:
                        CursorRequests.getPointerMapping(client, inputStream, outputStream);
                        break;
                    case 119:
                        KeyboardRequests.getModifierMapping(client, inputStream, outputStream);
                        break;
                    case 127:
                        client.skipRequest();
                        break;
                    default:
                        throw new UnsupportedOperationException("Unsupported opcode " + ((int) opcode) + ".");
                }
            }
        } catch (XRequestError e) {
            client.skipRequest();
            e.sendError(client, opcode);
        }
        return true;
    }
}
