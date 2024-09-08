---
title: GLErrorType
description: a error type of the gl 
generator: doxide
---


# GLErrorType

**enum GLErrorType : uint32_t**

a error type of the gl

**GLErrorNone = GL_NO_ERROR**
:   No error has been recorded. The value of this symbolic constant is guaranteed to be 0.

**GLErrorInvalidEnum = GL_INVALID_ENUM**
:   An unacceptable value is specified for an enumerated argument. The offending command is
ignored and has no other side effect than to set the error flag.

**GLErrorInvalidValue = GL_INVALID_VALUE**
:   A numeric argument is out of range. The offending command is ignored and has no other side
effect than to set the error flag.

**GLErrorInvalidOperation = GL_INVALID_OPERATION**
:   The specified operation is not allowed in the current state. The offending command is
ignored and has no other side effect than to set the error flag.

**GLErrorInvalidFramebufferOperation = GL_INVALID_OPERATION**
:   The command is trying to render to or read from the framebuffer while the currently bound
framebuffer is not framebuffer complete (i.e. the return value from glCheckFramebufferStatus
is not GL_FRAMEBUFFER_COMPLETE). The offending command is ignored and has no other side
effect than to set the error flag.

**GLErrorOutOfMemory = GL_OUT_OF_MEMORY**
:   There is not enough memory left to execute the command. The state of the GL is undefined,
except for the state of the error flags, after this error is recorded.
