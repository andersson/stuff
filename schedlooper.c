#define _GNU_SOURCE
#include <sys/sysinfo.h>
#include <sys/wait.h>
#include <sched.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	cpu_set_t set;
	int ncpus;
	int ret;
	int i;

	ncpus = get_nprocs_conf();
	printf("%d CPUs\n", ncpus);

	for (i = 0; i < ncpus; i++) {
		CPU_ZERO(&set);
		CPU_SET(i, &set);

		ret = sched_setaffinity(getpid(), sizeof(set), &set);
		if (ret < 0)
			fprintf(stderr, "failed to set affinity to %d\n", i);
		else
			printf("affinity set to %d\n", i);
	}

	return 0;
}
