

IF (NOT SANITIZER_TYPE STREQUAL "undefined")  # XXX

RECURSE(
    R-package
    app
    idl
    jvm-packages
    libs
    pytest
    python-package
    tools
)

IF (HAVE_CUDA)
RECURSE(
    cuda
)
ENDIF()

ENDIF()
