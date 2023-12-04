from distutils.core import setup
from catkin_pkg.python_setup import generate_distutils_setup

setup_args = generate_distutils_setup(
    packages=['hog_node'],  
    package_dir={'hog_node': 'src'},  # Python 소스 코드가 위치한 디렉토리
)

setup(**setup_args)
