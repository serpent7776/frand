#!/bin/sh

aggregate() {
	awk '
	{
		if ($0 in paths) {
			paths[$0]++;
		} else {
			paths[$0] = 1;
		}
	}
	END {
		OFS="	"
		for (path in paths) {
			print path, paths[path];
		}
	}
	'
}

(for i in $(seq 1 1000); do
	./frand ../test
done) | aggregate
