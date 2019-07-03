#include <iostream>
#include <boost/filesystem.hpp>
#include "lib/StreamSampler/StreamSampler.h"

int main(int argc, char *argv[])
{
	const auto sample_sets_count = std::size_t {1};
	const auto sample_count = std::size_t {1};
	const auto source_dir = argc > 1 ? argv[1] : ".";
	if (boost::filesystem::exists(source_dir)) {
		StreamSampler::CStreamSamplerWOR_R0<std::string> sampler {sample_sets_count, sample_count};
		boost::filesystem::directory_iterator it {source_dir};
		for (const auto& p : it) {
			sampler.AddElement(std::move(p.path().string()));
		}
		const auto sample_sets = sampler.GetSampleSets();
		assert(sample_sets.size() == sample_sets_count);
		assert(sample_sets[0].size() == sample_count);
		const auto& sampled_path = sample_sets[0][0];
		std::cout << sampled_path << "\n";
		return 0;
	} else {
		std::cout << "directory " << source_dir << " does not exist\n";
		return 1;
	}
}
