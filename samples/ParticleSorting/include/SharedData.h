//
//  SharedData.h
//  ParticleSorting
//
//  Created by William Lindmeier on 11/13/15.
//
//

#pragma once

#include "MetalConstants.h"
#include <simd/simd.h>

#define kParticleDimension 128 // Must be a power of 2 for the bitonic sort to work
#define kNumStages  8
#define kNumPasses  8

struct sortState_t
{
    unsigned int direction = 1; // 1 == ascending, 0 == descending
    unsigned int stage = 0;
    unsigned int pass = 0;
    unsigned int passNum = 0;
};


struct debugInfo_t
{
    vector_int4 int4s[16];
    
    unsigned int completedStages[kNumStages];
    unsigned int completedPasses[kNumPasses];
    unsigned int previousStage[kNumStages];
    unsigned int previousPass[kNumPasses];
    
    unsigned int numInt4s = 0;
    
    unsigned int maxStage = 0;
    unsigned int maxPass = 0;
    unsigned int minStage = 512;
    unsigned int minPass = 512;
    
    unsigned int lastPass = 999;
    unsigned int lastStage = 999;
    
    unsigned int numTimesAccessed = 0;
    
    int duplicateBlock = -1;
    bool hasDuplicateIndices = false;
    vector_int4 duplicateIndices;
    vector_int4 duplicateIndicesStart;
    int duplicateStage = -1;
    int duplicatePass = -1;
    int duplicateIndex = -1;
    
};

struct myUniforms_t
{
    unsigned int numParticles = kParticleDimension * kParticleDimension;
    matrix_float4x4 projectionMatrix;
    matrix_float4x4 viewMatrix;
    matrix_float4x4 modelMatrix;
    matrix_float4x4 inverseModelMatrix;
    matrix_float4x4 modelViewMatrix;
    matrix_float4x4 modelViewProjectionMatrix;
    matrix_float4x4 normalMatrix;
    matrix_float4x4 inverseViewMatrix;
};