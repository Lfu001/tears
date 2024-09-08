---
title: TextureScope
description: a class that bind and set texture parameters 
generator: doxide
---


# TextureScope

**class TextureScope**

a class that bind and set texture parameters

## Variables

| Name | Description |
| ---- | ----------- |
| [currentTextureUnit](#currentTextureUnit) | current texture unit  |
| [targetTexture](#targetTexture) | a texture to be controlled  |
| [backupMinFilter](#backupMinFilter) | a backup of min filter  |
| [backupMagFilter](#backupMagFilter) | a backup of mag filter  |
| [backupWrapS](#backupWrapS) | a backup of wrap S  |
| [backupWrapT](#backupWrapT) | a backup of wrap T  |

## Operators

| Name | Description |
| ---- | ----------- |
| [operator=](#operator_u003d) | copy assignment operator  |
| [operator=](#operator_u003d) | move assignment operator  |

## Functions

| Name | Description |
| ---- | ----------- |
| [TextureScope](#TextureScope) | default constructor  |
| [TextureScope](#TextureScope) | copy constructor  |
| [TextureScope](#TextureScope) | move constructor  |
| [TextureScope](#TextureScope) | constructor (min, mag, wrapS, wrapT)  |
| [TextureScope](#TextureScope) | constructor (min-mag, wrapS-wrapT)  |
| [~TextureScope](#_u007eTextureScope) | destructor  |
| [getCurrentTextureUnit](#getCurrentTextureUnit) | get current texture unit  |

## Variable Details

### backupMagFilter<a name="backupMagFilter"></a>

!!! variable "TextureParameterType backupMagFilter"

    a backup of mag filter

### backupMinFilter<a name="backupMinFilter"></a>

!!! variable "TextureParameterType backupMinFilter"

    a backup of min filter

### backupWrapS<a name="backupWrapS"></a>

!!! variable "TextureParameterType backupWrapS"

    a backup of wrap S

### backupWrapT<a name="backupWrapT"></a>

!!! variable "TextureParameterType backupWrapT"

    a backup of wrap T

### currentTextureUnit<a name="currentTextureUnit"></a>

!!! variable "static int currentTextureUnit"

    current texture unit

### targetTexture<a name="targetTexture"></a>

!!! variable "Texture&#42; targetTexture"

    a texture to be controlled

## Operator Details

### operator=<a name="operator_u003d"></a>

!!! function "TextureScope&amp; operator=(const TextureScope&amp;) = delete"

    copy assignment operator

!!! function "TextureScope&amp; operator=(TextureScope&amp;&amp;) = delete"

    move assignment operator

## Function Details

### TextureScope<a name="TextureScope"></a>

!!! function "TextureScope() = delete"

    default constructor

!!! function "TextureScope(const TextureScope&amp;) = delete"

    copy constructor

!!! function "TextureScope(TextureScope&amp;&amp;) = delete"

    move constructor

!!! function "TextureScope( Texture&#42; texture, TextureParameterType minFilter, TextureParameterType magFilter, TextureParameterType wrapS, TextureParameterType wrapT)"

    constructor (min, mag, wrapS, wrapT)

!!! function "TextureScope(Texture&#42; texture, TextureParameterType minMagFilter, TextureParameterType wrapST)"

    constructor (min-mag, wrapS-wrapT)

### getCurrentTextureUnit<a name="getCurrentTextureUnit"></a>

!!! function "int getCurrentTextureUnit()"

    get current texture unit

### ~TextureScope<a name="_u007eTextureScope"></a>

!!! function "virtual ~TextureScope()"

    destructor
