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
	requires = "cereal/master"
	exports_sources = "include/*"

	def package(self):
		copy(self, "*.h", path.join(self.source_folder, "include"), path.join(self.package_folder, "include"))
