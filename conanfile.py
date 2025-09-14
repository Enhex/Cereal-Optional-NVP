from os import path
from conan import ConanFile
from conan.tools.files import copy


class CerealoptionalnvpConan(ConanFile):
	name = "cereal_optional_nvp"
	version = "master"
	license = "MIT"
	url = "https://github.com/Enhex/Cereal-Optional-NVP"
	description = "Implementation of optionally loading name value pairs if they exist."
	# No settings/options are necessary, this is header only
	exports_sources = "include/*"
	package_type = "header-library"

	def requirements(self):
		self.requires("cereal/master", transitive_headers=True)

	def package(self):
		copy(self, "*.h", self.source_folder, self.package_folder)

	def package_id(self):
		self.info.clear()