project('iprof', 'c')

sys = host_machine.system()
cc = meson.get_compiler('c')

iprof_files = files('prof_gather.c', 'prof_process.c')
if sys == 'windows'
  iprof_files += 'prof_win32.c'
endif

if sys == 'linux' or sys == 'darwin' or sys == 'freebsd' or sys == 'netbsd' or sys == 'freebsd'
  iprof_files += 'prof_posix.c'
endif

iprof_deps = cc.find_library('m')

iprof = library('iprof', iprof_files, dependencies : iprof_deps)

iprof_dep = declare_dependency(
  link_with : iprof,
  include_directories : include_directories('.'),
  dependencies : iprof_deps,
)

if meson.version().version_compare('>= 0.54.0')
    meson.override_dependency('iprof', iprof_dep)
endif

if get_option('iprof_build_example')
  example_deps = [cc.find_library('raylib'), cc.find_library('m')]
  if sys == 'windows'
    example_deps += cc.find_library('opengl32')
  endif
  if sys == 'linux'
    example_deps += [ cc.find_library('X11'), cc.find_library('GL') ]
  endif
  example = executable('example', 'example.c', dependencies : example_deps, link_with : iprof)
endif
