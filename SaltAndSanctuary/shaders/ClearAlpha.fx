float4 ClearAlphaPS(float2 texCoord : TEXCOORD0) : COLOR0
{
    return float4(1.0, 1.0, 1.0, 0.0);
}

technique ClearAlphaTechnique
{
    pass Pass1
    {
        PixelShader = compile ps_3_0 ClearAlphaPS();
    }
}