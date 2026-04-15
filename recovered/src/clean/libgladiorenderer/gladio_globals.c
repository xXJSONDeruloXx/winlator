/*
 * gladio_globals.c — Global state for libgladiorenderer
 *
 * Thread-local renderer, global mutex, EGL shared context.
 */
#include "gladio_types.h"
#include <string.h>

/* Global mutex protecting GL context creation/destruction */
pthread_mutex_t glx_context_mutex = PTHREAD_MUTEX_INITIALIZER;

/* Shared EGL context for context-sharing across threads */
EGLContext globalEGLContext = EGL_NO_CONTEXT;

/* Thread-local: current active GLX renderer for this thread */
__thread GLXContext *currentRenderer = NULL;
