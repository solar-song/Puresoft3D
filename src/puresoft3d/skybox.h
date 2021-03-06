#pragma once

#pragma pack(16)
__declspec(align(16)) struct PROCDATA_DEF04
{
	float direction[4];
};
#pragma pack()

class VertexProcesserDEF04 : public PuresoftVertexProcessor
{
public:
	VertexProcesserDEF04(void);
	~VertexProcesserDEF04(void);

	void preprocess(const PURESOFTUNIFORM* uniforms);
	void process(const VertexProcessorInput* input, VertexProcessorOutput* output) const;

private:
	const float* m_P;
	const float* m_V;
};

class InterpolationProcessorDEF04 : public PuresoftInterpolationProcessor
{
public:
	InterpolationProcessorDEF04(void);
	~InterpolationProcessorDEF04(void);

	size_t userDataBytes(void) const;
	void preprocess(const PURESOFTUNIFORM* uniforms);
	void interpolateByContributes(void* interpolatedUserData, const void** vertexUserData, const float* correctedContributes) const;
	void calcStep(void* interpolatedUserDataStep, const void* interpolatedUserDataStart, const void* interpolatedUserDataEnd, int stepCount) const;
	void correctInterpolation(void* interpolatedUserData, const void* interpolatedUserDataStart, float correctionFactor2) const;
	void stepForward(void* interpolatedUserDataStart, const void* interpolatedUserDataStep, int stepCount) const;
};

class FragmentProcessorDEF04 : public PuresoftFragmentProcessor
{
public:
	FragmentProcessorDEF04(void);
	~FragmentProcessorDEF04(void);

	void preprocess(const PURESOFTUNIFORM* uniforms, const void** textures);
	void process(const FragmentProcessorInput* input, FragmentProcessorOutput* output) const;

private:
	const PuresoftFBO* m_skyboxTex;
};