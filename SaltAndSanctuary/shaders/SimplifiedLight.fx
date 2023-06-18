sampler lightTex;
sampler cloudsTex;

float2 scroll = { 0.0f, 0.0f };
float2 scroll2 = { 0.0f, 0.0f };
float2 scroll3 = { 0.0f, 0.0f };

float2 scrollDif = { 0.0f, 0.0f };

float alpha = 1.0f;
float lightFac = 1.0f;

float4 LightMap(float2 texCoord : TEXCOORD0) : COLOR0
{	
	float4 col = tex2D(lightTex, texCoord);
	
	float aFac = col.r;
	// if (aFac > 0.5f)
	// 	aFac = 1.0f - aFac;
	// aFac *= 4.0f;
	// if (aFac > 1.0f)
	// 	aFac = 1.0f;
	// OR
	// The original code created a downwards V
	aFac = saturate(-(abs(aFac-0.5f)-0.5f)*4.0f);
	// OR
	//aFac = smoothstep(0.0, 0.25, aFac) + smoothstep(1.0, 0.75, aFac) - 1;

	float c = dot(col, 1.0f / 3.0f);
	c += aFac * lightFac;
	//c = smoothstep(-0.1f, 0.96f, c);
	c = saturate(c);

	return float4(c, c, c, alpha); 
}

technique LightMapTechnique
{
	pass P0
	{
		PixelShader = compile ps_3_0 LightMap();
	}
}
