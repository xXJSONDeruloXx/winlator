package com.winlator.xenvironment.components;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import com.winlator.core.FileUtils;
import com.winlator.core.NetworkHelper;
import com.winlator.xenvironment.EnvironmentComponent;
import java.io.File;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class NetworkInfoUpdateComponent extends EnvironmentComponent {
    private BroadcastReceiver broadcastReceiver;

    @Override // com.winlator.xenvironment.EnvironmentComponent
    public void start() {
        Context context = this.environment.getContext();
        final NetworkHelper networkHelper = new NetworkHelper(context);
        updateIFAddrsFile(networkHelper.getIFAddresses());
        updateEtcHostsFile(networkHelper.getIPv4Address());
        this.broadcastReceiver = new BroadcastReceiver() { // from class: com.winlator.xenvironment.components.NetworkInfoUpdateComponent.1
            @Override // android.content.BroadcastReceiver
            public void onReceive(Context context2, Intent intent) {
                NetworkInfoUpdateComponent.this.updateIFAddrsFile(networkHelper.getIFAddresses());
                NetworkInfoUpdateComponent.this.updateEtcHostsFile(networkHelper.getIPv4Address());
            }
        };
        IntentFilter filter = new IntentFilter();
        filter.addAction("android.net.conn.CONNECTIVITY_CHANGE");
        context.registerReceiver(this.broadcastReceiver, filter);
    }

    @Override // com.winlator.xenvironment.EnvironmentComponent
    public void stop() {
        if (this.broadcastReceiver != null) {
            this.environment.getContext().unregisterReceiver(this.broadcastReceiver);
            this.broadcastReceiver = null;
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public void updateIFAddrsFile(List<NetworkHelper.IFAddress> ifAddresses) {
        File file = new File(this.environment.getRootFS().getTmpDir(), "ifaddrs");
        String content = "";
        if (!ifAddresses.isEmpty()) {
            for (NetworkHelper.IFAddress ifAddress : ifAddresses) {
                StringBuilder sb = new StringBuilder();
                sb.append(content);
                sb.append(!content.isEmpty() ? "\n" : "");
                sb.append(ifAddress.toString());
                content = sb.toString();
            }
        } else {
            content = new NetworkHelper.IFAddress().toString();
        }
        FileUtils.writeString(file, content);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public void updateEtcHostsFile(String ipAddress) {
        String ip = ipAddress != null ? ipAddress : "127.0.0.1";
        File file = new File(this.environment.getRootFS().getRootDir(), "etc/hosts");
        FileUtils.writeString(file, ip + "\tlocalhost\n");
    }
}
