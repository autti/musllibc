static inline struct pthread *__pthread_self()
{
#ifdef __clang__
	char *tp;
	__asm__ __volatile__ ("or %0, tp, x0" : "=r" (tp) );
#else
	register char *tp __asm__("tp");
#endif
	return (struct pthread *) (tp - sizeof(struct pthread));
}

#define TLS_ABOVE_TP
#define TP_ADJ(p) ((char *)(p) + sizeof(struct pthread))

/* word-offset to 'pc' in mcontext_t */
#define CANCEL_REG_IP 32
