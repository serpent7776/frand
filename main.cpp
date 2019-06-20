#include <iostream>
#include <boost/filesystem.hpp>
#include "lib/StreamSampler/StreamSampler.h"

int main(int argc, char *argv[])
{
	auto sample_sets_count = std::size_t {1};
	auto sample_count = std::size_t {1};
	StreamSampler::CStreamSamplerWOR_R0<std::string> sampler {sample_sets_count, sample_count};
	boost::filesystem::directory_iterator it {"."};
	for (const auto& p : it) {
		sampler.AddElement(std::move(p.path().string()));
	}
	auto sample_sets = sampler.GetSampleSets();
	assert(sample_sets.size() == 1);
	assert(sample_sets[0].size() == 1);
	const auto& sampled_path = sample_sets[0][0];
	std::cout << sampled_path << "\n";
	return 0;
}
