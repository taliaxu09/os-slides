project(
  '03-libraries',
  'c',
  default_options : ['c_std=c17', 'warning_level=3', 'c_args=-D_DEFAULT_SOURCE']
)

executable(
  'alloc-example',
  'alloc-example.c',
)

executable(
  'atexit-example',
  'atexit-example.c',
)

shared_library('alloc-wrapper', 'alloc-wrapper.c')

inc_v1 = include_directories('v1')
inc_v2 = include_directories('v2')

subdir('v1')
subdir('v2')

executable(
  'point-example-compile-v1-link-v1',
  'point-example.c',
  include_directories : inc_v1,
  link_with : [point_v1],
)

executable(
  'point-example-compile-v1-link-v2',
  'point-example.c',
  include_directories : inc_v1,
  link_with : [point_v2],
)

executable(
  'point-example-compile-v2-link-v1',
  'point-example.c',
  include_directories : inc_v2,
  link_with : [point_v1],
)

executable(
  'point-example-compile-v2-link-v2',
  'point-example.c',
  include_directories : inc_v2,
  link_with : [point_v2],
)
