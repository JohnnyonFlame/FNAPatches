// Pixel shader applies a one dimensional gaussian blur filter.
// This is used twice by the bloom postprocess, first to
// blur horizontally, and then again to blur vertically.

texture SampleTexture : register(t0);
sampler2D s0_sampler = sampler_state {
	Texture = (SampleTexture);
	MagFilter = Linear;
	MinFilter = Linear;
	AddressU = Clamp;
	AddressV = Clamp;
};

#define SAMPLE_COUNT 7

float2 SampleOffsets[SAMPLE_COUNT];
float SampleWeights[SAMPLE_COUNT];

float4 PixelShaderFunction(float2 texCoord : TEXCOORD0) : COLOR0
{
	float4 c = 0;
	
	// Combine a number of weighted image filter taps.
	for (int i = 0; i < SAMPLE_COUNT; i++)
	{
		c += tex2D(s0_sampler, texCoord + SampleOffsets[i]) * SampleWeights[i];
	}
	
	return c;
}


technique GaussianBlur
{
	pass Pass1
	{
		PixelShader = compile ps_3_0 PixelShaderFunction();
	}
}
