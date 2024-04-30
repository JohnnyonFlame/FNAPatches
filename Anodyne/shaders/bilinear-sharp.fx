#define _vs(r)  : register(vs, r)
#define _ps(r)  : register(ps, r)
#define _cb(r)

float4x4 MatrixTransform    _vs(c0) _cb(c0);

texture s0_texture : register(t0);
sampler2D s0_sampler = sampler_state {
    Texture = (s0_texture);
    MagFilter = Linear;
    MinFilter = Linear;
    AddressU = Clamp;
    AddressV = Clamp;
};

float2 TexSize;
float2 Scale;

float4 SpritePixelShader(float4 color : COLOR0,
                         float2 texCoord : TEXCOORD0) : SV_Target0
{
    float2 vTexCoord = (texCoord * TexSize);
	float2 texel_floored = floor(vTexCoord);
	float2 s = frac(vTexCoord);
	float2 region_range = 0.5 - 0.5 / Scale;	
	float2 center_dist = s - 0.5;
	float2 f = (center_dist - clamp(center_dist, -region_range, region_range)) * Scale + 0.5;
	float2 mod_texel = texel_floored + f;
	float4 col = tex2D(s0_sampler, mod_texel / TexSize);
    return col;
}

technique SpriteBatch
{
    pass P0
    {
        PixelShader  = compile ps_3_0 SpritePixelShader();
    }
}
