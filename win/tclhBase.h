#ifndef TCLHBASE_H
#define TCLHBASE_H

/* Common definitions included by all Tcl helper *implemenations* */
#ifndef TCLH_EMBEDDER
#error TCLH_EMBEDDER not defined. Please #define this to name of your package.
#endif

#undef TCLH_INLINE
#ifdef _MSC_VER
# define TCLH_INLINE __inline
#else
# define TCLH_INLINE static inline
#endif

#ifndef TCLH_PANIC
#define TCLH_PANIC Tcl_Panic
#endif

#ifndef TCLH_ASSERT
# ifdef NDEBUG
#  define TCLH_ASSERT(bool_) (void) 0
# else
#  define TCLH_ASSERT(bool_) (void)( (bool_) || (TCLH_PANIC("Assertion (%s) failed at line %d in file %s.", #bool_, __LINE__, __FILE__), 0) )
# endif
#endif

TCLH_INLINE char *Tclh_memdup(void *from, int len) {
    void *to = ckalloc(len);
    memcpy(to, from, len);
    return to;
}

TCLH_INLINE int Tclh_strlen(const char *s) {
    return (int) strlen(s);
}

TCLH_INLINE char *Tclh_strdup(const char *from) {
    int len = Tclh_strlen(from) + 1;
    char *to = ckalloc(len);
    memcpy(to, from, len);
    return to;
}

TCLH_INLINE char *Tclh_strdupn(const char *from, int len) {
    char *to = ckalloc(len+1);
    memcpy(to, from, len);
    to[len] = '\0';
    return to;
}



#endif /* TCLHBASE_H */