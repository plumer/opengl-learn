### `glClearColor(r, g, b, a)`

Set current clearing color. First seen on page 36.

### `glClear(GLbitfield mask)`

Clear the specified buffer to the current clearing values. First seen on page 36.
Available buffers:

* GL_COLOR_BUFFER_BIT
* GL_DEPTH_BUFFER_BIT
* GL_ACCUM_BUFFER_BIT
* GL_STENCIL_BUFFER_BIT

### `glFlush()`

The one you always forget. First seen on page 39.

### `glFinish()`

A stronger version over `glFlush()`, but use with care - often unnecessary.

### `glRect{sifd}(x1, y1, x2, y2)`

Just like drag out a rectangle from (x1, y1) to (x2, y2). **Vector version available.**

### `glVertex[234]{sifd}(x, y, z, ...)

Specify a vertex. The *so far* most important function.

### `glBegin(mode)`

Available `mode` values:

* GL_POINTS
* GL_LINES
* GL_LINE_STRIP
* GL_LINE_LOOP
* GL_TRIANGLES
* GL_TRIANGLE_STRIP
* GL_TRIANGLE_FAN
* GL_QUADS
* GL_QUAD_STRIP
* GL_POLYGON

### `glEnable(capability)`, `glDisable(capability)`, `glIsEnabled(capability)`

Available `capability`s: unknown and unimportant.

### `glGet{Boolean,Integer,Float,Double,Pointer}v(stateName, params)

`stateName` refers to any of the state, e.g. `GL_CURRENT_COLOR`.

`params` points to the array to write the content of states.

### `glPointSize(GLfloat size)`

Set the width in **pixels** for rendered points. Effective in `GL_POINTS` mode.

Get point **size range** with 
`glGetFloatv(GL_ALIASED_POINT_SIZE_RANGE, param)`, or
`glGetFloatv(GL_SMOOTH_POINT_SIZE_RANGE, param)`

### `glLineWidth(GLfloat width)`

Set the width in **pixels** for rendered lines. `width` must > 0.0.

Get line width **range** with
`glGetFloatv(GL_ALIASED_LINE_WIDTH_RANGE, param)`, or its SMOOTH version

### `glLineStipple(GLint factor, GLushort pattern)`

Set the current stippling pattern for lines. 
`pattern` is 16-bit unsigned integer interpreted as 'continuous' on 1-bits and 'incontinuous' on 0-bits. Each bit maps to exactly a pixel, or specified by `factor`.
`factor` is by default 1, ranging from 1 to 256.
Line stippling **must** be enabled by enabling `GL_LINE_STIPPLE` by `glEnable()`.
