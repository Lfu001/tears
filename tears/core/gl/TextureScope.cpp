//
//  TextureScope.cpp
//  tears
//
//  Created by Lfu001 on 2024/05/04.
//  Copyright © 2024 tears team. All rights reserved.
//

#include "gl/GLController.hpp"
#include "gl/Texture.hpp"
#include "utils/DebugUtil.hpp"
#include "TextureScope.hpp"

namespace tears {

// current texture unit
int TextureScope::currentTextureUnit = 0;

// constructor (min, mag, wrapS, wrapT)
TextureScope::TextureScope(
    Texture* texture,
    TextureParameterType minFilter,
    TextureParameterType magFilter,
    TextureParameterType wrapS,
    TextureParameterType wrapT) {
    tears_assert(texture);
    tears_assert(minFilter == TextureParameterNearest || minFilter == TextureParameterLinear);
    tears_assert(magFilter == TextureParameterNearest || magFilter == TextureParameterLinear);
    tears_assert(
        wrapS == TextureParameterClampToEdge || wrapS == TextureParameterRepeat
        || wrapS == TextureParameterMirroredRepeat);
    tears_assert(
        wrapT == TextureParameterClampToEdge || wrapT == TextureParameterRepeat
        || wrapT == TextureParameterMirroredRepeat);

    GLController* gl = GLController::getInstance();
    gl->setActiveTextureUnit(++currentTextureUnit);
    gl->bindTexture(texture);
    targetTexture = texture;
    // backup texture parameters
    backupMinFilter = texture->getTextureParameter(TextureParameterNameMinFilter);
    backupMagFilter = texture->getTextureParameter(TextureParameterNameMagFilter);
    backupWrapS = texture->getTextureParameter(TextureParameterNameWrapS);
    backupWrapT = texture->getTextureParameter(TextureParameterNameWrapT);
    // set texture parameters
    texture->setTextureParameter(TextureParameterNameMinFilter, minFilter);
    texture->setTextureParameter(TextureParameterNameMagFilter, magFilter);
    texture->setTextureParameter(TextureParameterNameWrapS, wrapS);
    texture->setTextureParameter(TextureParameterNameWrapT, wrapT);
}

// constructor (min-mag, wrapS-wrapT)
TextureScope::TextureScope(
    Texture* texture,
    TextureParameterType minMagFilter,
    TextureParameterType wrapST):
    TextureScope(texture, minMagFilter, minMagFilter, wrapST, wrapST) {}

// destructor
TextureScope::~TextureScope() {
    try {
        GLController* gl = GLController::getInstance();
        gl->bindTexture(nullptr);
        gl->setActiveTextureUnit(--currentTextureUnit);
        // restore texture parameters from backup
        targetTexture->setTextureParameter(TextureParameterNameMinFilter, backupMinFilter);
        targetTexture->setTextureParameter(TextureParameterNameMagFilter, backupMagFilter);
        targetTexture->setTextureParameter(TextureParameterNameWrapS, backupWrapS);
        targetTexture->setTextureParameter(TextureParameterNameWrapT, backupWrapT);
    } catch (...) {
        tears_assert(false);
    }
}

}    // namespace tears
