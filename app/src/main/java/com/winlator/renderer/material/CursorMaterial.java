package com.winlator.renderer.material;

import com.winlator.renderer.material.ShaderMaterial;

/* JADX INFO: loaded from: classes.dex */
public class CursorMaterial extends ShaderMaterial {
    public final Uniforms uniforms = new Uniforms();

    public static class Uniforms {
        public final ShaderMaterial.Uniform xform = new ShaderMaterial.Uniform("xform");
        public final ShaderMaterial.Uniform viewSize = new ShaderMaterial.Uniform("viewSize");
        public final ShaderMaterial.Uniform texture = new ShaderMaterial.Uniform("texture");
        public final ShaderMaterial.Uniform backColor = new ShaderMaterial.Uniform("backColor");
        public final ShaderMaterial.Uniform foreColor = new ShaderMaterial.Uniform("foreColor");
    }

    @Override // com.winlator.renderer.material.ShaderMaterial
    protected String getVertexShader() {
        return String.join("\n", "uniform float xform[6];", "uniform vec2 viewSize;", "attribute vec2 position;", "varying vec2 vUV;", "void main() {", "vUV = position;", "vec2 transformedPos = applyXForm(position, xform);", "gl_Position = vec4(2.0 * transformedPos.x / viewSize.x - 1.0, 1.0 - 2.0 * transformedPos.y / viewSize.y, 0.0, 1.0);", "}");
    }

    @Override // com.winlator.renderer.material.ShaderMaterial
    protected String getFragmentShader() {
        return String.join("\n", "precision mediump float;", "uniform sampler2D texture;", "uniform vec3 backColor;", "uniform vec3 foreColor;", "varying vec2 vUV;", "void main() {", "vec4 texelColor = texture2D(texture, vUV);", "gl_FragColor = vec4(mix(foreColor, backColor, texelColor.r), texelColor.a);", "}");
    }
}
