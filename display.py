import fputs
import vanaj
import exmod

print("fputs doc:", fputs.__doc__)
print("vanaj doc:", vanaj.__doc__)
print("exmod doc:", exmod.__doc__)

# Build:
# pipenv run setup2.py build

# Install:
# pipenv run setup2.py install
# fputs.fputs("Test", "write2.txt") # Less than 10 long, throws an error
fputs.fputs("Test5678910", "write2.txt")

vanaj.run()

exmod.say_hello("Hello from Python")
print(exmod.add(1, 2))

