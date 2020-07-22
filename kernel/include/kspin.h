typedef volatile int spin_mutex;

void lock_spin_mutex(spin_mutex *mut);
void unlock_spin_mutex(spin_mutex *mut);
