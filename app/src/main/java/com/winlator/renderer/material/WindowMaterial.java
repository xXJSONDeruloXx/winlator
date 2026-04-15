package com.winlator.renderer.material;

import com.winlator.renderer.material.ShaderMaterial;

/* JADX INFO: loaded from: classes.dex */
public class WindowMaterial extends ShaderMaterial {
    public final Uniforms uniforms = new Uniforms();

    public static class Uniforms {
        public final ShaderMaterial.Uniform xform = new ShaderMaterial.Uniform("xform");
        public final ShaderMaterial.Uniform viewSize = new ShaderMaterial.Uniform("viewSize");
        public final ShaderMaterial.Uniform texture = new ShaderMaterial.Uniform("texture");
        public final ShaderMaterial.Uniform noAlpha = new ShaderMaterial.Uniform("noAlpha");
        public final ShaderMaterial.Uniform flipY = new ShaderMaterial.Uniform("flipY");
    }

    @Override // com.winlator.renderer.material.ShaderMaterial
    protected String getVertexShader() {
        return String.join("\n", "uniform float xform[6];", "uniform vec2 viewSize;", "uniform bool flipY;", "attribute vec2 position;", "varying vec2 vUV;", "void main() {", "vUV = vec2(position.x, flipY ? (1.0 - position.y) : position.y);", "vec2 transformedPos = applyXForm(position, xform);", "gl_Position = vec4(2.0 * transformedPos.x / viewSize.x - 1.0, 1.0 - 2.0 * transformedPos.y / viewSize.y, 0.0, 1.0);", "}");
    }

    @Override // com.winlator.renderer.material.ShaderMaterial
    protected String getFragmentShader() {
        return String.join("\n", "precision mediump float;", "uniform sampler2D texture;", "uniform float noAlpha;", "varying vec2 vUV;", "void main() {", "vec4 texelColor = texture2D(texture, vUV);", "gl_FragColor = vec4(texelColor.rgb, max(texelColor.a, noAlpha));", "}");
    }
}
