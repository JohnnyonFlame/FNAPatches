// parchment.fx
// XNA

sampler samplerState;

float pX;
float pY;
float pA;
float r;
float g;
float b;

float4 Parchment(float2 texCoord : TEXCOORD0) : COLOR0
{
	float2 tex = texCoord;
	float4 col = float4(r, g, b, 0.0f);
	
	float dif;
	float2 vDif = texCoord - 0.5f;
	vDif *= vDif;
	dif = vDif.x + vDif.y;

	float2 texFrac = frac(tex + float2(pX, pY));
	texFrac -= step(-texFrac, 0.0);
#if HAS_GRAIN > 0
	col.a += tex2D(samplerState, texFrac).r * dif * pA;
#else
	col.a += 0.55f * dif * pA;
#endif
	return col; 
}

technique ParchmentTechnique
{
	pass P0
	{
		PixelShader = compile ps_3_0 Parchment();
	}
}
