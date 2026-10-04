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

example_deps = [cc.find_library('raylib'), cc.find_library('m')]
if sys == 'windows'
  example_deps += cc.find_library('opengl32')
endif
if sys == 'linux'
  example_deps += [ cc.find_library('X11'), cc.find_library('GL') ]
endif
example = executable('example', 'example.c', dependencies : example_deps, link_with : iprof)
