import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/taylor/Documents/robotics-testing-repo/scrb-introtask/install/intro_py_pkg'
