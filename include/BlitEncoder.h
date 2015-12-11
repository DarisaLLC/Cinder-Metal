//
//  BlitEncoder.hpp
//  MetalCube
//
//  Created by William Lindmeier on 10/17/15.
//
//

#pragma once

#include "cinder/Cinder.h"
#include "TextureBuffer.h"
#include "DataBuffer.h"

namespace cinder { namespace mtl {
    
    typedef std::shared_ptr<class BlitEncoder> BlitEncoderRef;
    
    class BlitEncoder
    {
        
        friend class CommandBuffer;
        
    public:

        virtual ~BlitEncoder();
        
        void * getNative(){ return mImpl; }
        
        void endEncoding();
        
        void synchronizeResource( void * mtlResource ); // MTLResource
        
        void synchronizeTexture( const TextureBufferRef & texture, uint slice, uint level);

        void copyFromTextureToTexture(const TextureBufferRef & sourceTexture, uint sourceSlice, uint sourceLevel, ivec3 sourceOrigin, ivec3 sourceSize, TextureBufferRef & destTexture, uint destSlice, uint destLevel, ivec3 destOrigin);

        void copyFromBufferToTexture( const DataBufferRef & sourceBuffer, uint sourceOffset, uint sourceBytesPerRow, uint sourceBytesPerImage, ivec3 sourceSize, TextureBufferRef & destTexture, uint destSlice, uint destLevel, ivec3 destOrigin, BlitOption options = BlitOptionNone );

        void copyFromTextureToBuffer( const TextureBufferRef & sourceTexture, uint sourceSlice, uint sourceLevel, ivec3 sourceOrigin, ivec3 sourceSize, const DataBufferRef & destinationBuffer, uint destinationOffset, uint destinationBytesPerRow, uint destinationBytesPerImage, BlitOption options = BlitOptionNone );

        void generateMipmapsForTexture( const TextureBufferRef & texture );

        void fillBuffer( DataBufferRef buffer, uint8_t value, uint length, uint offset = 0 );

        void copyFromBufferToBuffer( DataBufferRef & sourceBuffer, uint sourceOffset, DataBufferRef & destBuffer, uint destOffset, uint length);

    protected:
        
        static BlitEncoderRef create( void * mtlBlitCommandEncoder );
        
        BlitEncoder( void * mtlBlitCommandEncoder );
        
        void * mImpl = NULL; // <MTLBlitCommandEncoder>
        
    };
    
} }