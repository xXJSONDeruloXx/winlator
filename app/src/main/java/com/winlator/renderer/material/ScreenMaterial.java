package com.winlator.renderer.material;

import com.winlator.renderer.material.ShaderMaterial;

/* JADX INFO: loaded from: classes.dex */
public class ScreenMaterial extends ShaderMaterial {
    public final Uniforms uniforms = new Uniforms();

    public static class Uniforms {
        public final ShaderMaterial.Uniform resolution = new ShaderMaterial.Uniform("resolution");
        public final ShaderMaterial.Uniform screenTexture = new ShaderMaterial.Uniform("screenTexture");
        public final ShaderMaterial.Uniform flipY = new ShaderMaterial.Uniform("flipY");
    }

    @Override // com.winlator.renderer.material.ShaderMaterial
    protected String getVertexShader() {
        return String.join("\n", "attribute vec2 position;", "varying vec2 vUV;", "uniform bool flipY;", "void main() {", "vUV = vec2(position.x, flipY ? (1.0 - position.y) : position.y);", "gl_Position = vec4(2.0 * position.x - 1.0, 2.0 * position.y - 1.0, 0.0, 1.0);", "}");
    }

    @Override // com.winlator.renderer.material.ShaderMaterial
    protected String getFragmentShader() {
        return String.join("\n", "precision mediump float;", "uniform sampler2D screenTexture;", "varying vec2 vUV;", "void main() {", "gl_FragColor = texture2D(screenTexture, vUV);", "}");
    }
}
