from conans import ConanFile, tools
import os


class CerealoptionalnvpConan(ConanFile):
	name = "cereal_optional_nvp"
	version = "master"
	license = "MIT"
	url = "https://github.com/Enhex/Cereal-Optional-NVP"
	description = "Implementation of optionally loading name value pairs if they exist."
	# No settings/options are necessary, this is header only
	requires = "cereal/master@enhex/stable"
	exports_sources = "include/*"

	def package(self):
		self.copy("*.h")
