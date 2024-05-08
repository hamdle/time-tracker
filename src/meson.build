inc_dirs = [
	include_directories('gui'),
]

timer_tracker_sources = [
  'main.c',
  'timer-tracker-application.c',
  'gui/timer-tracker-window.c',
]

timer_tracker_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1', version: '>= 1.4'),
]

timer_tracker_sources += gnome.compile_resources('timer-tracker-resources',
  'timer-tracker.gresource.xml',
  c_name: 'timer_tracker'
)

executable('timer-tracker', timer_tracker_sources,
  dependencies: timer_tracker_deps,
  include_directories: inc_dirs,
       install: true,
)
