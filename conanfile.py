from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, layout, CMakeDeps


class AppConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = {"shared": False}

    def requirements(self):
        self.requires("fmt/10.1.1")

    def configure(self):
        pass

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()

        tc = CMakeToolchain(self)
        tc.generate()

    def layout(self):
        layout.cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
