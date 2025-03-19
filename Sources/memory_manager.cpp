#include"memory_manager.h"
#include"logger.h"
#include<cassert>
void* safe_malloc(size_t size)
{
    assert(size>0);
    void * ptr = nullptr;
#if defined(__STDC_VERSION__)&&__STDC_VERSION__>=201112L
    ptr = _aligned_malloc(alignof(max_align_t),size);
#else
    ptr = malloc(size);
#endif
    if(ptr==nullptr)
    {
        fprintf(stderr,"Memory allocation failed for size %zu.\n",size);
        assert(ptr!=nullptr);
    }
    return ptr;
}
void* safe_remalloc(void* ptr, size_t newsize)
{
    void* newptr=realloc(ptr,newsize);
    if(!newptr)
    {
        log_message(LOG_ERROR,"Failed to reallocate to %zu bytes of memory",newsize);
    }
    return newptr;
}
void safe_free(void** ptr)
{
    if(ptr&&*ptr)
    {
        free(*ptr);
        *ptr=nullptr;
    }
    else{
        log_message(LOG_WARNING,"Attempted to free a null or already freed porinter");
    }
}