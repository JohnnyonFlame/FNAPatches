// mapblood.fx
// XNA

sampler bloodSampler;
float bloodAlpha;
float bloodSat;

struct PS_INPUT 
{ 
	float4 Color : COLOR0;
	float2 TexCoord : TEXCOORD0; 
	float4 VPos : VPOS;
}; 

float4 MapBlood(PS_INPUT Input) : COLOR0 
{
	float2 tex = Input.TexCoord;
	
	float4 blood = tex2D(bloodSampler, tex);
	float4 color;
	float c = blood.a * bloodAlpha * Input.Color.a * 0.75;
	color.rgb = blood.rgb * Input.Color.rgb * c;
	// Make the darker spots take more of the color away. Make it black.
	color.rgb += c * float3(0.35, 0.45, 0.45);

    return float4(color.rgb, 1.0);
}

technique PostBlood 
{ 
	pass P0
	{ 
		PixelShader = compile ps_3_0 MapBlood(); 
	} 
}