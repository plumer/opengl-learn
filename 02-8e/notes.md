`GLuint glGetUniformBlockIndex(
		GLuint program,
		const char * uniformBlockName
)`

Returns the index of the named uniform block 
specified by uniformBlockName associated with `program`.
If `uniformBlockName` is not a valid uniform block of program,
`GL_INVALI_INDEX` is returned.

Referenced on page 63.

`void glBindBufferRange(
		GLenum	target,
		GLuint	index,
		GLuint	buffer,
		GLintptr	offset,
		GLsizeiptr	size
)`,

`void glBindBufferBase(
		GLenum	target,
		GLuint	index,
		GLuint	buffer
)`

Associates the buffer object buffer with the named uniform block
associated with `index`.

More details on page 64.
