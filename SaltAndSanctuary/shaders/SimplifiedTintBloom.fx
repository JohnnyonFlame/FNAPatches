struct InputStruct {
	float4 param0 : COLOR;
	float4 param1 : TEXCOORD;
	float4 param2 : POSITION;
};

struct OutputStruct {
	float4 param0 : COLOR;
	float4 param1 : TEXCOORD;
	float4 Position : SV_Position;
};

texture s0_texture : register(t0);
sampler2D s0_sampler = sampler_state {
	Texture = (s0_texture);
	MagFilter = Linear;
	MinFilter = Linear;
	AddressU = Clamp;
	AddressV = Clamp;
};

float4x4 MatrixTransform;
float3 tintColor;
float a;
float tint;
float sat;
float screenSizeX;
float screenSizeY;
float detailAlpha;
float detailX1;
float detailX2;
float detailY1;
float detailY2;

float4 PixelShaderFunction(
	float4 color : COLOR0,
	float2 texCoord : TEXCOORD0,
	float4 vpos : VPOS) : SV_Target0
{
	float4 col = tex2D(s0_sampler, texCoord) * color;
	float stint = tint * a;
	col.rgb = lerp(col.rgb, tintColor, stint);
	
	float b = dot(col.rgb, 1 / 3.0f);
	float isat = saturate(1.0f - sat);

	// Mix color channels
	col.rgb = lerp(col.rgb, float3(b, b, b), isat);
	// Pre-multiplied alpha
	col.rgb *= (col.a * a);

	return col;
}

technique Technique1
{
	pass Pass1
	{
		PixelShader = compile ps_3_0 PixelShaderFunction();
	}
}