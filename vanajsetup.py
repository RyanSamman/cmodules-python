from distutils.core import setup, Extension

def main():
    setup(name="vanaj",
          version="1.0.0",
          description="Python interface for vanaj",
          author="vanaj uwu",
          author_email="your_email@gmail.com",
          ext_modules=[Extension("vanaj", ["vanajmodule.c"])])

if __name__ == "__main__":
    main()