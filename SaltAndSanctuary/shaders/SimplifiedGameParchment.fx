// gameparch.fx
// XNA

sampler samplerState;

float baseFac = 1.0f;
float parchFac = 1.0f;
float h;
float frame = 0.0f;

struct PS_INPUT
{
	float2 TexCoord : TEXCOORD0;
};

#define USE_GRAIN 1
float4 Parchment(PS_INPUT Input) : COLOR0
{
	float2 tex = Input.TexCoord;
	
#if USE_GRAIN > 0
	// Check `fxc.exe SimplifiedGameParchment.fx /O3 /Cc /T fx_2_0` for why the code
	// is like this. Most of these calculations will be performed on the preshader,
	// effectively lowering this effect from three texel fetches to two, while also
	// reducing the amount of arithmetic instructions required.

	// Is the number lower than [0, 1]?
	float f1 = (1.0f - step(1.0f, frame));

	// Is the number between [1, 2]?
	float f2 = (1.0f - step(2.0f, frame)) * (1.0 - f1);

	// Is the number between [2, 3]?
	float f3 = (1.0f - step(3.0f, frame)) * (1.0 - f2);

	// Select a pair of coordinates based on which group the number was contained within
	float4 f_tex = 0.0f;
	f_tex += f1 * float4(tex.x, tex.y, 1.0f - tex.x, tex.y);
	f_tex += f2 * float4(1.0f - tex.x, tex.y, tex.x, 1.0f - tex.y);
	f_tex += f3 * float4(tex.x, 1.0f - tex.y, tex.x, tex.y);

	// Calculate the coefficients
	float2 coef = float2(ceil(frame) - frame, frame - floor(frame));
#if USE_GRAIN == 2
	// Fetch the textures
	float r = tex2D(samplerState, f_tex.xy).r * (coef.x) +
	          tex2D(samplerState, f_tex.zw).r * (coef.y);
#else // USE_GRAIN == 2
	float r = tex2D(samplerState, f_tex.xy).r * (coef.x + coef.y);
#endif // USE_GRAIN == 2
#else // USE_GRAIN > 0
	float2 coef = float2(ceil(frame) - frame, frame - floor(frame));
	// Grain texture average brightness is ~0.55f
	float r = 0.55f * (coef.x + coef.y);
#endif // USE_GRAIN > 0
	float4 rVal = 0.0f;

	float aFac = 1.0f - (tex.y / h);

	rVal.a = aFac * baseFac;
	rVal.a += r * aFac * parchFac;
	rVal.rgb = 1.0f;

	return rVal; 
}

technique ParchmentTechnique
{
	pass P0
	{
		PixelShader = compile ps_3_0 Parchment();
	}
}
