#include "../../kspin.h"

void lock_spin_mutex(spin_mutex *mut) {
	while (!__sync_bool_compare_and_swap(mut, 0, 1));
	__sync_synchronize();
}

void unlock_spin_mutex(spin_mutex *mut) {
	__sync_synchronize();
	*mut = 0;
}
