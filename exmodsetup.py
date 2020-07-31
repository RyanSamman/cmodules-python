from distutils.core import setup, Extension

module1 = Extension('exmod', ['exmodmodule.c'])

setup(
	name = 'exmod',
	version = '1.0',
	description = 'This is an example package',
	author = 'Ryan',
	url = "none",
	ext_modules = [module1]
)