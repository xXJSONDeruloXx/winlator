package com.winlator.renderer.material;

import android.graphics.Color;
import android.opengl.GLES20;

/* JADX INFO: loaded from: classes.dex */
public abstract class ShaderMaterial {
    public int programId;

    protected abstract String getFragmentShader();

    protected abstract String getVertexShader();

    public static class Uniform {
        public int location = -1;
        public final String name;

        public Uniform(String name) {
            this.name = name;
        }
    }

    protected static int compileShaders(String vertexShader, String fragmentShader) {
        int beginIndex = vertexShader.indexOf("void main() {");
        String vertexShader2 = vertexShader.substring(0, beginIndex) + "vec2 applyXForm(vec2 p, float xform[6]) {\nreturn vec2(xform[0] * p.x + xform[2] * p.y + xform[4], xform[1] * p.x + xform[3] * p.y + xform[5]);\n}\n" + vertexShader.substring(beginIndex);
        int programId = GLES20.glCreateProgram();
        int[] compiled = new int[1];
        int vertexShaderId = GLES20.glCreateShader(35633);
        GLES20.glShaderSource(vertexShaderId, vertexShader2);
        GLES20.glCompileShader(vertexShaderId);
        GLES20.glGetShaderiv(vertexShaderId, 35713, compiled, 0);
        if (compiled[0] == 0) {
            throw new RuntimeException("Could not compile vertex shader: \n" + GLES20.glGetShaderInfoLog(vertexShaderId));
        }
        GLES20.glAttachShader(programId, vertexShaderId);
        int fragmentShaderId = GLES20.glCreateShader(35632);
        GLES20.glShaderSource(fragmentShaderId, fragmentShader);
        GLES20.glCompileShader(fragmentShaderId);
        GLES20.glGetShaderiv(fragmentShaderId, 35713, compiled, 0);
        if (compiled[0] == 0) {
            throw new RuntimeException("Could not compile fragment shader: \n" + GLES20.glGetShaderInfoLog(fragmentShaderId));
        }
        GLES20.glAttachShader(programId, fragmentShaderId);
        GLES20.glLinkProgram(programId);
        GLES20.glDeleteShader(vertexShaderId);
        GLES20.glDeleteShader(fragmentShaderId);
        return programId;
    }

    public void use() {
        if (this.programId == 0) {
            this.programId = compileShaders(getVertexShader(), getFragmentShader());
        }
        GLES20.glUseProgram(this.programId);
    }

    private int getUniformLocation(Uniform uniform) {
        int i = uniform.location;
        if (i != -1) {
            return i;
        }
        int i2 = this.programId;
        int location = i2 != 0 ? GLES20.glGetUniformLocation(i2, uniform.name) : -1;
        uniform.location = location;
        return location;
    }

    public void destroy() {
        GLES20.glDeleteProgram(this.programId);
        this.programId = 0;
    }

    public void setUniformColor(Uniform uniform, int color) {
        int location = getUniformLocation(uniform);
        if (location != -1) {
            GLES20.glUniform3f(location, Color.red(color) * 0.003921569f, Color.green(color) * 0.003921569f, Color.blue(color) * 0.003921569f);
        }
    }

    public void setUniformFloat(Uniform uniform, float value) {
        int location = getUniformLocation(uniform);
        if (location != -1) {
            GLES20.glUniform1f(location, value);
        }
    }

    public void setUniformFloatArray(Uniform uniform, float[] values) {
        int location = getUniformLocation(uniform);
        if (location != -1) {
            GLES20.glUniform1fv(location, values.length, values, 0);
        }
    }

    public void setUniformInt(Uniform uniform, int value) {
        int location = getUniformLocation(uniform);
        if (location != -1) {
            GLES20.glUniform1i(location, value);
        }
    }

    public void setUniformBool(Uniform uniform, boolean z) {
        setUniformInt(uniform, z ? 1 : 0);
    }

    public void setUniformVec2(Uniform uniform, float x, float y) {
        int location = getUniformLocation(uniform);
        if (location != -1) {
            GLES20.glUniform2f(location, x, y);
        }
    }
}
