from cx_Freeze import setup, Executable


setup(
    name="test",
    version="1.0",
    description="Test application",
    author="lxp",
    executables=[Executable("main.py")]
)