
typedef struct Il2CppClass Il2CppClass;
typedef struct Il2CppType Il2CppType;
typedef struct EventInfo EventInfo;
typedef struct MethodInfo MethodInfo;
typedef struct FieldInfo FieldInfo;
typedef struct PropertyInfo PropertyInfo;

typedef struct MonoClass MonoClass;
typedef struct MonoType MonoType;
typedef struct MonoTable MonoTable;
typedef struct MonoMethodSignature MonoMethodSignature;

typedef struct Il2CppAssembly Il2CppAssembly;
typedef struct Il2CppArray Il2CppArray;
typedef struct Il2CppDelegate Il2CppDelegate;
typedef struct Il2CppDomain Il2CppDomain;
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppException Il2CppException;
typedef struct Il2CppProfiler Il2CppProfiler;
typedef struct Il2CppObject Il2CppObject;
typedef struct Il2CppReflectionMethod Il2CppReflectionMethod;
typedef struct Il2CppReflectionType Il2CppReflectionType;
typedef struct Il2CppString Il2CppString;
typedef struct Il2CppThread Il2CppThread;
typedef struct Il2CppAsyncResult Il2CppAsyncResult;
typedef struct Il2CppManagedMemorySnapshot Il2CppManagedMemorySnapshot;
typedef struct Il2CppCustomAttrInfo Il2CppCustomAttrInfo;

typedef struct MonoAssembly MonoAssembly;
typedef struct MonoArray MonoArray;
typedef struct MonoDelegate MonoDelegate;
typedef struct MonoDomain MonoDomain;
typedef struct MonoImage MonoImage;
typedef struct MonoException MonoException;
typedef struct MonoProfiler MonoProfiler;
typedef struct MonoObject MonoObject;
typedef struct MonoReflectionMethod MonoReflectionMethod;
typedef struct MonoReflectionType MonoReflectionType;
typedef struct MonoString MonoString;
typedef struct MonoThread MonoThread;
typedef struct MonoAsyncResult MonoAsyncResult;
typedef struct MonoManagedMemorySnapshot MonoManagedMemorySnapshot;
typedef struct MonoCustomAttrInfo MonoCustomAttrInfo;

typedef enum
{
	IL2CPP_PROFILE_NONE = 0,
	IL2CPP_PROFILE_APPDOMAIN_EVENTS = 1 << 0,
	IL2CPP_PROFILE_ASSEMBLY_EVENTS = 1 << 1,
	IL2CPP_PROFILE_MODULE_EVENTS = 1 << 2,
	IL2CPP_PROFILE_CLASS_EVENTS = 1 << 3,
	IL2CPP_PROFILE_JIT_COMPILATION = 1 << 4,
	IL2CPP_PROFILE_INLINING = 1 << 5,
	IL2CPP_PROFILE_EXCEPTIONS = 1 << 6,
	IL2CPP_PROFILE_ALLOCATIONS = 1 << 7,
	IL2CPP_PROFILE_GC = 1 << 8,
	IL2CPP_PROFILE_THREADS = 1 << 9,
	IL2CPP_PROFILE_REMOTING = 1 << 10,
	IL2CPP_PROFILE_TRANSITIONS = 1 << 11,
	IL2CPP_PROFILE_ENTER_LEAVE = 1 << 12,
	IL2CPP_PROFILE_COVERAGE = 1 << 13,
	IL2CPP_PROFILE_INS_COVERAGE = 1 << 14,
	IL2CPP_PROFILE_STATISTICAL = 1 << 15,
	IL2CPP_PROFILE_METHOD_EVENTS = 1 << 16,
	IL2CPP_PROFILE_MONITOR_EVENTS = 1 << 17,
	IL2CPP_PROFILE_IOMAP_EVENTS = 1 << 18, /* this should likely be removed, too */
	IL2CPP_PROFILE_GC_MOVES = 1 << 19,
	IL2CPP_PROFILE_FILEIO = 1 << 20
} Il2CppProfileFlags;

typedef enum
{
	IL2CPP_PROFILE_FILEIO_WRITE = 0,
	IL2CPP_PROFILE_FILEIO_READ
} Il2CppProfileFileIOKind;

typedef enum
{
	IL2CPP_GC_EVENT_START,
	IL2CPP_GC_EVENT_MARK_START,
	IL2CPP_GC_EVENT_MARK_END,
	IL2CPP_GC_EVENT_RECLAIM_START,
	IL2CPP_GC_EVENT_RECLAIM_END,
	IL2CPP_GC_EVENT_END,
	IL2CPP_GC_EVENT_PRE_STOP_WORLD,
	IL2CPP_GC_EVENT_POST_STOP_WORLD,
	IL2CPP_GC_EVENT_PRE_START_WORLD,
	IL2CPP_GC_EVENT_POST_START_WORLD
} Il2CppGCEvent;

typedef enum
{
	IL2CPP_STAT_NEW_OBJECT_COUNT,
	IL2CPP_STAT_INITIALIZED_CLASS_COUNT,
	//IL2CPP_STAT_GENERIC_VTABLE_COUNT,
	//IL2CPP_STAT_USED_CLASS_COUNT,
	IL2CPP_STAT_METHOD_COUNT,
	//IL2CPP_STAT_CLASS_VTABLE_SIZE,
	IL2CPP_STAT_CLASS_STATIC_DATA_SIZE,
	IL2CPP_STAT_GENERIC_INSTANCE_COUNT,
	IL2CPP_STAT_GENERIC_CLASS_COUNT,
	IL2CPP_STAT_INFLATED_METHOD_COUNT,
	IL2CPP_STAT_INFLATED_TYPE_COUNT,
	//IL2CPP_STAT_DELEGATE_CREATIONS,
	//IL2CPP_STAT_MINOR_GC_COUNT,
	//IL2CPP_STAT_MAJOR_GC_COUNT,
	//IL2CPP_STAT_MINOR_GC_TIME_USECS,
	//IL2CPP_STAT_MAJOR_GC_TIME_USECS
} Il2CppStat;

typedef enum
{
	IL2CPP_UNHANDLED_POLICY_LEGACY,
	IL2CPP_UNHANDLED_POLICY_CURRENT
} Il2CppRuntimeUnhandledExceptionPolicy;

typedef struct Il2CppStackFrameInfo
{
	const MethodInfo* method;
} Il2CppStackFrameInfo;

typedef struct
{
	void* (*malloc_func)(size_t size);
	void* (*aligned_malloc_func)(size_t size, size_t alignment);
	void (*free_func)(void* ptr);
	void (*aligned_free_func)(void* ptr);
	void* (*calloc_func)(size_t nmemb, size_t size);
	void* (*realloc_func)(void* ptr, size_t size);
	void* (*aligned_realloc_func)(void* ptr, size_t size, size_t alignment);
} Il2CppMemoryCallbacks;


typedef wchar_t Il2CppChar;
typedef wchar_t Il2CppNativeChar;
#define IL2CPP_NATIVE_STRING(str) L##str

typedef void (*il2cpp_register_object_callback)(Il2CppObject** arr, int size, void* userdata);
typedef void (*il2cpp_WorldChangedCallback)();
typedef void (*Il2CppFrameWalkFunc) (const Il2CppStackFrameInfo* info, void* user_data);
typedef void (*Il2CppProfileFunc) (Il2CppProfiler* prof);
typedef void (*Il2CppProfileMethodFunc) (Il2CppProfiler* prof, const MethodInfo* method);
typedef void (*Il2CppProfileAllocFunc) (Il2CppProfiler* prof, Il2CppObject* obj, Il2CppClass* klass);
typedef void (*Il2CppProfileGCFunc) (Il2CppProfiler* prof, Il2CppGCEvent event, int generation);
typedef void (*Il2CppProfileGCResizeFunc) (Il2CppProfiler* prof, int64_t new_size);
typedef void (*Il2CppProfileFileIOFunc) (Il2CppProfiler* prof, Il2CppProfileFileIOKind kind, int count);
typedef void (*Il2CppProfileThreadFunc) (Il2CppProfiler* prof, unsigned long tid);

typedef const Il2CppNativeChar* (*Il2CppSetFindPlugInCallback)(const Il2CppNativeChar*);
typedef void (*Il2CppLogCallback)(const char*);

typedef void (*Il2CppMethodPointer)();
typedef uintptr_t il2cpp_array_size_t;
#define ARRAY_LENGTH_AS_INT32(a) ((int32_t)a)

DO_API(void, il2cpp_init, (const char* domain_name));
DO_API(void, il2cpp_init_utf16, (const Il2CppChar* domain_name));
DO_API(void, il2cpp_shutdown, ());
DO_API(void, il2cpp_dumping_memory, (bool val));
DO_API(void, il2cpp_set_config_dir, (const char* config_path));
DO_API(void, il2cpp_set_data_dir, (const char* data_path));
DO_API(void, il2cpp_set_temp_dir, (const char* temp_path));
DO_API(void, il2cpp_set_commandline_arguments, (int argc, const char* const argv[], const char* basedir));
DO_API(void, il2cpp_set_commandline_arguments_utf16, (int argc, const Il2CppChar* const argv[], const char* basedir));
DO_API(void, il2cpp_set_config_utf16, (const Il2CppChar* executablePath));
DO_API(void, il2cpp_set_config, (const char* executablePath));

DO_API(void, il2cpp_set_memory_callbacks, (Il2CppMemoryCallbacks* callbacks));
DO_API(const Il2CppImage*, il2cpp_get_corlib, ());
DO_API(void, il2cpp_add_internal_call, (const char* name, Il2CppMethodPointer method));
DO_API(Il2CppMethodPointer, il2cpp_resolve_icall, (const char* name));

DO_API(void*, il2cpp_alloc, (size_t size));
DO_API(void, il2cpp_free, (void* ptr));

// array
DO_API(Il2CppClass*, il2cpp_array_class_get, (Il2CppClass* element_class, uint32_t rank));
DO_API(uint32_t, il2cpp_array_length, (Il2CppArray* array));
DO_API(uint32_t, il2cpp_array_get_byte_length, (Il2CppArray* array));
DO_API(Il2CppArray*, il2cpp_array_new, (Il2CppClass* elementTypeInfo, il2cpp_array_size_t length));
DO_API(Il2CppArray*, il2cpp_array_new_specific, (Il2CppClass* arrayTypeInfo, il2cpp_array_size_t length));
DO_API(Il2CppArray*, il2cpp_array_new_full, (Il2CppClass* array_class, il2cpp_array_size_t* lengths, il2cpp_array_size_t* lower_bounds));
DO_API(Il2CppClass*, il2cpp_bounded_array_class_get, (Il2CppClass* element_class, uint32_t rank, bool bounded));
DO_API(int, il2cpp_array_element_size, (const Il2CppClass* array_class));

// assembly
DO_API(const Il2CppImage*, il2cpp_assembly_get_image, (const Il2CppAssembly* assembly));

// class
DO_API(const Il2CppType*, il2cpp_class_enum_basetype, (Il2CppClass* klass));
DO_API(bool, il2cpp_class_is_generic, (const Il2CppClass* klass));
DO_API(bool, il2cpp_class_is_inflated, (const Il2CppClass* klass));
DO_API(bool, il2cpp_class_is_assignable_from, (Il2CppClass* klass, Il2CppClass* oklass));
DO_API(bool, il2cpp_class_is_subclass_of, (Il2CppClass* klass, Il2CppClass* klassc, bool check_interfaces));
DO_API(bool, il2cpp_class_has_parent, (Il2CppClass* klass, Il2CppClass* klassc));
DO_API(Il2CppClass*, il2cpp_class_from_il2cpp_type, (const Il2CppType* type));
DO_API(Il2CppClass*, il2cpp_class_from_name, (const Il2CppImage* image, const char* namespaze, const char* name));
DO_API(Il2CppClass*, il2cpp_class_from_system_type, (Il2CppReflectionType* type));
DO_API(Il2CppClass*, il2cpp_class_get_element_class, (Il2CppClass* klass));
DO_API(const EventInfo*, il2cpp_class_get_events, (Il2CppClass* klass, void** iter));
DO_API(FieldInfo*, il2cpp_class_get_fields, (Il2CppClass* klass, void** iter));
DO_API(Il2CppClass*, il2cpp_class_get_nested_types, (Il2CppClass* klass, void** iter));
DO_API(Il2CppClass*, il2cpp_class_get_interfaces, (Il2CppClass* klass, void** iter));
DO_API(const PropertyInfo*, il2cpp_class_get_properties, (Il2CppClass* klass, void** iter));
DO_API(const PropertyInfo*, il2cpp_class_get_property_from_name, (Il2CppClass* klass, const char* name));
DO_API(FieldInfo*, il2cpp_class_get_field_from_name, (Il2CppClass* klass, const char* name));
DO_API(const MethodInfo*, il2cpp_class_get_methods, (Il2CppClass* klass, void** iter));
DO_API(const MethodInfo*, il2cpp_class_get_method_from_name, (Il2CppClass* klass, const char* name, int argsCount));
DO_API(const char*, il2cpp_class_get_name, (Il2CppClass* klass));
DO_API(const char*, il2cpp_class_get_namespace, (Il2CppClass* klass));
DO_API(Il2CppClass*, il2cpp_class_get_parent, (Il2CppClass* klass));
DO_API(Il2CppClass*, il2cpp_class_get_declaring_type, (Il2CppClass* klass));
DO_API(int32_t, il2cpp_class_instance_size, (Il2CppClass* klass));
DO_API(size_t, il2cpp_class_num_fields, (const Il2CppClass* enumKlass));
DO_API(bool, il2cpp_class_is_valuetype, (const Il2CppClass* klass));
DO_API(int32_t, il2cpp_class_value_size, (Il2CppClass* klass, uint32_t* align));
DO_API(bool, il2cpp_class_is_blittable, (const Il2CppClass* klass));
DO_API(int, il2cpp_class_get_flags, (const Il2CppClass* klass));
DO_API(bool, il2cpp_class_is_abstract, (const Il2CppClass* klass));
DO_API(bool, il2cpp_class_is_interface, (const Il2CppClass* klass));
DO_API(int, il2cpp_class_array_element_size, (const Il2CppClass* klass));
DO_API(Il2CppClass*, il2cpp_class_from_type, (const Il2CppType* type));
DO_API(const Il2CppType*, il2cpp_class_get_type, (Il2CppClass* klass));
DO_API(uint32_t, il2cpp_class_get_type_token, (Il2CppClass* klass));
DO_API(bool, il2cpp_class_has_attribute, (Il2CppClass* klass, Il2CppClass* attr_class));
DO_API(bool, il2cpp_class_has_references, (Il2CppClass* klass));
DO_API(bool, il2cpp_class_is_enum, (const Il2CppClass* klass));
DO_API(const Il2CppImage*, il2cpp_class_get_image, (Il2CppClass* klass));
DO_API(const char*, il2cpp_class_get_assemblyname, (const Il2CppClass* klass));
DO_API(int, il2cpp_class_get_rank, (const Il2CppClass* klass));

// testing only
DO_API(size_t, il2cpp_class_get_bitmap_size, (const Il2CppClass* klass));
DO_API(void, il2cpp_class_get_bitmap, (Il2CppClass* klass, size_t* bitmap));

// stats
DO_API(bool, il2cpp_stats_dump_to_file, (const char* path));
DO_API(uint64_t, il2cpp_stats_get_value, (Il2CppStat stat));

// domain
DO_API(Il2CppDomain*, il2cpp_domain_get, ());
DO_API(const Il2CppAssembly*, il2cpp_domain_assembly_open, (Il2CppDomain* domain, const char* name));
DO_API(const Il2CppAssembly**, il2cpp_domain_get_assemblies, (const Il2CppDomain* domain, size_t* size));

// exception
DO_API(void, il2cpp_raise_exception, (Il2CppException*));
DO_API(Il2CppException*, il2cpp_exception_from_name_msg, (const Il2CppImage* image, const char* name_space, const char* name, const char* msg));
DO_API(Il2CppException*, il2cpp_get_exception_argument_null, (const char* arg));
DO_API(void, il2cpp_format_exception, (const Il2CppException* ex, char* message, int message_size));
DO_API(void, il2cpp_format_stack_trace, (const Il2CppException* ex, char* output, int output_size));
DO_API(void, il2cpp_unhandled_exception, (Il2CppException*));

// field
DO_API(int, il2cpp_field_get_flags, (FieldInfo* field));
DO_API(const char*, il2cpp_field_get_name, (FieldInfo* field));
DO_API(Il2CppClass*, il2cpp_field_get_parent, (FieldInfo* field));
DO_API(size_t, il2cpp_field_get_offset, (FieldInfo* field));
DO_API(const Il2CppType*, il2cpp_field_get_type, (FieldInfo* field));
DO_API(void, il2cpp_field_get_value, (Il2CppObject* obj, FieldInfo* field, void* value));
DO_API(Il2CppObject*, il2cpp_field_get_value_object, (FieldInfo* field, Il2CppObject* obj));
DO_API(bool, il2cpp_field_has_attribute, (FieldInfo* field, Il2CppClass* attr_class));
DO_API(void, il2cpp_field_set_value, (Il2CppObject* obj, FieldInfo* field, void* value));
DO_API(void, il2cpp_field_static_get_value, (FieldInfo* field, void* value));
DO_API(void, il2cpp_field_static_set_value, (FieldInfo* field, void* value));
DO_API(void, il2cpp_field_set_value_object, (Il2CppObject* instance, FieldInfo* field, Il2CppObject* value));

// gc
DO_API(void, il2cpp_gc_collect, (int maxGenerations));
DO_API(int32_t, il2cpp_gc_collect_a_little, ());
DO_API(void, il2cpp_gc_disable, ());
DO_API(void, il2cpp_gc_enable, ());
DO_API(bool, il2cpp_gc_is_disabled, ());
DO_API(int64_t, il2cpp_gc_get_used_size, ());
DO_API(int64_t, il2cpp_gc_get_heap_size, ());
DO_API(void, il2cpp_gc_wbarrier_set_field, (Il2CppObject* obj, void** targetAddress, MonoObject* object));

// gchandle
DO_API(uint32_t, il2cpp_gchandle_new, (Il2CppObject* obj, bool pinned));
DO_API(uint32_t, il2cpp_gchandle_new_weakref, (Il2CppObject* obj, bool track_resurrection));
DO_API(Il2CppObject*, il2cpp_gchandle_get_target, (uint32_t gchandle));
DO_API(void, il2cpp_gchandle_free, (uint32_t gchandle));

// liveness
DO_API(void*, il2cpp_unity_liveness_calculation_begin, (Il2CppClass* filter, int max_object_count, il2cpp_register_object_callback callback, void* userdata, il2cpp_WorldChangedCallback onWorldStarted, il2cpp_WorldChangedCallback onWorldStopped));
DO_API(void, il2cpp_unity_liveness_calculation_end, (void* state));
DO_API(void, il2cpp_unity_liveness_calculation_from_root, (Il2CppObject* root, void* state));
DO_API(void, il2cpp_unity_liveness_calculation_from_statics, (void* state));

// method
DO_API(const Il2CppType*, il2cpp_method_get_return_type, (const MethodInfo* method));
DO_API(Il2CppClass*, il2cpp_method_get_declaring_type, (const MethodInfo* method));
DO_API(const char*, il2cpp_method_get_name, (const MethodInfo* method));
DO_API(const MethodInfo*, il2cpp_method_get_from_reflection, (const Il2CppReflectionMethod* method));
DO_API(Il2CppReflectionMethod*, il2cpp_method_get_object, (const MethodInfo* method, Il2CppClass* refclass));
DO_API(bool, il2cpp_method_is_generic, (const MethodInfo* method));
DO_API(bool, il2cpp_method_is_inflated, (const MethodInfo* method));
DO_API(bool, il2cpp_method_is_instance, (const MethodInfo* method));
DO_API(uint32_t, il2cpp_method_get_param_count, (const MethodInfo* method));
DO_API(const Il2CppType*, il2cpp_method_get_param, (const MethodInfo* method, uint32_t index));
DO_API(Il2CppClass*, il2cpp_method_get_class, (const MethodInfo* method));
DO_API(bool, il2cpp_method_has_attribute, (const MethodInfo* method, Il2CppClass* attr_class));
DO_API(uint32_t, il2cpp_method_get_flags, (const MethodInfo* method, uint32_t* iflags));
DO_API(uint32_t, il2cpp_method_get_token, (const MethodInfo* method));
DO_API(const char*, il2cpp_method_get_param_name, (const MethodInfo* method, uint32_t index));

// profiler
DO_API(void, il2cpp_profiler_install, (Il2CppProfiler* prof, Il2CppProfileFunc shutdown_callback));
DO_API(void, il2cpp_profiler_set_events, (Il2CppProfileFlags events));
DO_API(void, il2cpp_profiler_install_enter_leave, (Il2CppProfileMethodFunc enter, Il2CppProfileMethodFunc fleave));
DO_API(void, il2cpp_profiler_install_allocation, (Il2CppProfileAllocFunc callback));
DO_API(void, il2cpp_profiler_install_gc, (Il2CppProfileGCFunc callback, Il2CppProfileGCResizeFunc heap_resize_callback));
DO_API(void, il2cpp_profiler_install_fileio, (Il2CppProfileFileIOFunc callback));
DO_API(void, il2cpp_profiler_install_thread, (Il2CppProfileThreadFunc start, Il2CppProfileThreadFunc end));

// property
DO_API(uint32_t, il2cpp_property_get_flags, (PropertyInfo* prop));
DO_API(const MethodInfo*, il2cpp_property_get_get_method, (PropertyInfo* prop));
DO_API(const MethodInfo*, il2cpp_property_get_set_method, (PropertyInfo* prop));
DO_API(const char*, il2cpp_property_get_name, (PropertyInfo* prop));
DO_API(Il2CppClass*, il2cpp_property_get_parent, (PropertyInfo* prop));

// object
DO_API(Il2CppClass*, il2cpp_object_get_class, (Il2CppObject* obj));
DO_API(uint32_t, il2cpp_object_get_size, (Il2CppObject* obj));
DO_API(const MethodInfo*, il2cpp_object_get_virtual_method, (Il2CppObject* obj, const MethodInfo* method));
DO_API(Il2CppObject*, il2cpp_object_new, (const Il2CppClass* klass));
DO_API(void*, il2cpp_object_unbox, (Il2CppObject* obj));

DO_API(Il2CppObject*, il2cpp_value_box, (Il2CppClass* klass, void* data));

// monitor
DO_API(void, il2cpp_monitor_enter, (Il2CppObject* obj));
DO_API(bool, il2cpp_monitor_try_enter, (Il2CppObject* obj, uint32_t timeout));
DO_API(void, il2cpp_monitor_exit, (Il2CppObject* obj));
DO_API(void, il2cpp_monitor_pulse, (Il2CppObject* obj));
DO_API(void, il2cpp_monitor_pulse_all, (Il2CppObject* obj));
DO_API(void, il2cpp_monitor_wait, (Il2CppObject* obj));
DO_API(bool, il2cpp_monitor_try_wait, (Il2CppObject* obj, uint32_t timeout));

// runtime
DO_API(Il2CppObject*, il2cpp_runtime_invoke, (const MethodInfo* method, MonoObject* obj, void** params, Il2CppException** exc));
DO_API(Il2CppObject*, il2cpp_runtime_invoke_convert_args, (const MethodInfo* method, MonoObject* obj, Il2CppObject** params, int paramCount, Il2CppException** exc));
DO_API(void, il2cpp_runtime_class_init, (Il2CppClass* klass));
DO_API(void, il2cpp_runtime_object_init, (Il2CppObject* obj));

DO_API(void, il2cpp_runtime_object_init_exception, (Il2CppObject* obj, Il2CppException** exc));

DO_API(void, il2cpp_runtime_unhandled_exception_policy_set, (Il2CppRuntimeUnhandledExceptionPolicy value));

// string
DO_API(int32_t, il2cpp_string_length, (Il2CppString* str));
DO_API(Il2CppChar*, il2cpp_string_chars, (Il2CppString* str));
DO_API(Il2CppString*, il2cpp_string_new, (const char* str));
DO_API(Il2CppString*, il2cpp_string_new_len, (const char* str, uint32_t length));
DO_API(Il2CppString*, il2cpp_string_new_utf16, (const Il2CppChar* text, int32_t len));
DO_API(Il2CppString*, il2cpp_string_new_wrapper, (const char* str));
DO_API(Il2CppString*, il2cpp_string_intern, (Il2CppString* str));
DO_API(Il2CppString*, il2cpp_string_is_interned, (Il2CppString* str));

// thread
DO_API(Il2CppThread*, il2cpp_thread_current, ());
DO_API(Il2CppThread*, il2cpp_thread_attach, (Il2CppDomain* domain));
DO_API(void, il2cpp_thread_detach, (Il2CppThread* thread));

DO_API(Il2CppThread**, il2cpp_thread_get_all_attached_threads, (size_t* size));
DO_API(bool, il2cpp_is_vm_thread, (Il2CppThread* thread));

// stacktrace
DO_API(void, il2cpp_current_thread_walk_frame_stack, (Il2CppFrameWalkFunc func, void* user_data));
DO_API(void, il2cpp_thread_walk_frame_stack, (Il2CppThread* thread, Il2CppFrameWalkFunc func, void* user_data));
DO_API(bool, il2cpp_current_thread_get_top_frame, (Il2CppStackFrameInfo* frame));
DO_API(bool, il2cpp_thread_get_top_frame, (Il2CppThread* thread, Il2CppStackFrameInfo* frame));
DO_API(bool, il2cpp_current_thread_get_frame_at, (int32_t offset, Il2CppStackFrameInfo* frame));
DO_API(bool, il2cpp_thread_get_frame_at, (Il2CppThread* thread, int32_t offset, Il2CppStackFrameInfo* frame));
DO_API(int32_t, il2cpp_current_thread_get_stack_depth, ());
DO_API(int32_t, il2cpp_thread_get_stack_depth, (Il2CppThread* thread));

// type
DO_API(Il2CppObject*, il2cpp_type_get_object, (const Il2CppType* type));
DO_API(int, il2cpp_type_get_type, (const Il2CppType* type));
DO_API(Il2CppClass*, il2cpp_type_get_class_or_element_class, (const Il2CppType* type));
DO_API(char*, il2cpp_type_get_name, (const Il2CppType* type));
DO_API(bool, il2cpp_type_is_byref, (const Il2CppType* type));
DO_API(uint32_t, il2cpp_type_get_attrs, (const Il2CppType* type));
DO_API(bool, il2cpp_type_equals, (const Il2CppType* type, const Il2CppType* otherType));
DO_API(char*, il2cpp_type_get_assembly_qualified_name, (const Il2CppType* type));

// image
DO_API(const Il2CppAssembly*, il2cpp_image_get_assembly, (const Il2CppImage* image));
DO_API(const char*, il2cpp_image_get_name, (const Il2CppImage* image));
DO_API(const char*, il2cpp_image_get_filename, (const Il2CppImage* image));
DO_API(const MethodInfo*, il2cpp_image_get_entry_point, (const Il2CppImage* image));

DO_API(size_t, il2cpp_image_get_class_count, (const Il2CppImage* image));
DO_API(const Il2CppClass*, il2cpp_image_get_class, (const Il2CppImage* image, size_t index));

// Memory information
DO_API(Il2CppManagedMemorySnapshot*, il2cpp_capture_memory_snapshot, ());
DO_API(void, il2cpp_free_captured_memory_snapshot, (Il2CppManagedMemorySnapshot* snapshot));

DO_API(void, il2cpp_set_find_plugin_callback, (Il2CppSetFindPlugInCallback method));

// Logging
DO_API(void, il2cpp_register_log_callback, (Il2CppLogCallback method));

// Debugger
DO_API(void, il2cpp_debugger_set_agent_options, (const char* options));
DO_API(bool, il2cpp_is_debugger_attached, ());

// TLS module
DO_API(void, il2cpp_unity_install_unitytls_interface, (const void* unitytlsInterfaceStruct));

// custom attributes
DO_API(Il2CppCustomAttrInfo*, il2cpp_custom_attrs_from_class, (Il2CppClass* klass));
DO_API(Il2CppCustomAttrInfo*, il2cpp_custom_attrs_from_method, (const MethodInfo* method));

DO_API(Il2CppObject*, il2cpp_custom_attrs_get_attr, (Il2CppCustomAttrInfo* ainfo, Il2CppClass* attr_klass));
DO_API(bool, il2cpp_custom_attrs_has_attr, (Il2CppCustomAttrInfo* ainfo, Il2CppClass* attr_klass));
DO_API(Il2CppArray*, il2cpp_custom_attrs_construct, (Il2CppCustomAttrInfo* cinfo));

DO_API(void, il2cpp_custom_attrs_free, (Il2CppCustomAttrInfo* ainfo));

#define MONO_DATACOLLECTORVERSION 20221207 

#define MONOCMD_INITMONO 0
#define MONOCMD_OBJECT_GETCLASS 1
#define MONOCMD_ENUMDOMAINS 2
#define MONOCMD_SETCURRENTDOMAIN 3
#define MONOCMD_ENUMASSEMBLIES 4
#define MONOCMD_GETIMAGEFROMASSEMBLY 5
#define MONOCMD_GETIMAGENAME 6
#define MONOCMD_ENUMCLASSESINIMAGE 7
#define MONOCMD_ENUMFIELDSINCLASS 8
#define MONOCMD_ENUMMETHODSINCLASS 9
#define MONOCMD_COMPILEMETHOD 10

#define MONOCMD_GETMETHODHEADER 11
#define MONOCMD_GETMETHODHEADER_CODE 12
#define MONOCMD_LOOKUPRVA 13
#define MONOCMD_GETJITINFO 14
#define MONOCMD_FINDCLASS 15
#define MONOCMD_FINDMETHOD 16
#define MONOCMD_GETMETHODNAME 17
#define MONOCMD_GETMETHODCLASS 18
#define MONOCMD_GETCLASSNAME 19
#define MONOCMD_GETCLASSNAMESPACE 20
#define MONOCMD_FREEMETHOD 21
#define MONOCMD_TERMINATE 22
#define MONOCMD_DISASSEMBLE 23
#define MONOCMD_GETMETHODSIGNATURE 24
#define MONOCMD_GETPARENTCLASS 25
#define MONOCMD_GETSTATICFIELDADDRESSFROMCLASS 26
#define MONOCMD_GETTYPECLASS 27
#define MONOCMD_GETARRAYELEMENTCLASS 28
#define MONOCMD_FINDMETHODBYDESC 29
#define MONOCMD_INVOKEMETHOD 30
#define MONOCMD_LOADASSEMBLY 31
#define MONOCMD_GETFULLTYPENAME 32
#define MONOCMD_OBJECT_NEW 33
#define MONOCMD_OBJECT_INIT 34
#define MONOCMD_GETVTABLEFROMCLASS 35
#define MONOCMD_GETMETHODPARAMETERS 36
#define MONOCMD_ISCLASSGENERIC 37
#define MONOCMD_ISIL2CPP 38
#define MONOCMD_FILLOPTIONALFUNCTIONLIST 39
#define MONOCMD_GETSTATICFIELDVALUE 40
#define MONOCMD_SETSTATICFIELDVALUE 41
#define MONOCMD_GETCLASSIMAGE 42
#define MONOCMD_FREE 43
#define MONOCMD_GETIMAGEFILENAME 44
#define MONOCMD_GETCLASSNESTINGTYPE 45
#define MONOCMD_LIMITEDCONNECTION 46
#define MONOCMD_GETMONODATACOLLECTORVERSION 47
#define MONOCMD_NEWSTRING 48

typedef enum {
	MONO_TYPE_END = 0x00,       /* End of List */
	MONO_TYPE_VOID = 0x01,
	MONO_TYPE_BOOLEAN = 0x02,
	MONO_TYPE_CHAR = 0x03,
	MONO_TYPE_I1 = 0x04,
	MONO_TYPE_U1 = 0x05,
	MONO_TYPE_I2 = 0x06,
	MONO_TYPE_U2 = 0x07,
	MONO_TYPE_I4 = 0x08,
	MONO_TYPE_U4 = 0x09,
	MONO_TYPE_I8 = 0x0a,
	MONO_TYPE_U8 = 0x0b,
	MONO_TYPE_R4 = 0x0c,
	MONO_TYPE_R8 = 0x0d,
	MONO_TYPE_STRING = 0x0e,
	MONO_TYPE_PTR = 0x0f,       /* arg: <type> token */
	MONO_TYPE_BYREF = 0x10,       /* arg: <type> token */
	MONO_TYPE_VALUETYPE = 0x11,       /* arg: <type> token */
	MONO_TYPE_CLASS = 0x12,       /* arg: <type> token */
	MONO_TYPE_VAR = 0x13,	   /* number */
	MONO_TYPE_ARRAY = 0x14,       /* type, rank, boundsCount, bound1, loCount, lo1 */
	MONO_TYPE_GENERICINST = 0x15,	   /* <type> <type-arg-count> <type-1> \x{2026} <type-n> */
	MONO_TYPE_TYPEDBYREF = 0x16,
	MONO_TYPE_I = 0x18,
	MONO_TYPE_U = 0x19,
	MONO_TYPE_FNPTR = 0x1b,	      /* arg: full method signature */
	MONO_TYPE_OBJECT = 0x1c,
	MONO_TYPE_SZARRAY = 0x1d,       /* 0-based one-dim-array */
	MONO_TYPE_MVAR = 0x1e,       /* number */
	MONO_TYPE_CMOD_REQD = 0x1f,       /* arg: typedef or typeref token */
	MONO_TYPE_CMOD_OPT = 0x20,       /* optional arg: typedef or typref token */
	MONO_TYPE_INTERNAL = 0x21,       /* CLR internal type */

	MONO_TYPE_MODIFIER = 0x40,       /* Or with the following types */
	MONO_TYPE_SENTINEL = 0x41,       /* Sentinel for varargs method signature */
	MONO_TYPE_PINNED = 0x45,       /* Local var that points to pinned object */

	MONO_TYPE_ENUM = 0x55        /* an enumeration */
} MonoTypeEnum;

typedef enum {
	MONO_TABLE_MODULE,
	MONO_TABLE_TYPEREF,
	MONO_TABLE_TYPEDEF,
	MONO_TABLE_FIELD_POINTER,
	MONO_TABLE_FIELD,
	MONO_TABLE_METHOD_POINTER,
	MONO_TABLE_METHOD,
	MONO_TABLE_PARAM_POINTER,
	MONO_TABLE_PARAM,
	MONO_TABLE_INTERFACEIMPL,
	MONO_TABLE_MEMBERREF, /* 0xa */
	MONO_TABLE_CONSTANT,
	MONO_TABLE_CUSTOMATTRIBUTE,
	MONO_TABLE_FIELDMARSHAL,
	MONO_TABLE_DECLSECURITY,
	MONO_TABLE_CLASSLAYOUT,
	MONO_TABLE_FIELDLAYOUT, /* 0x10 */
	MONO_TABLE_STANDALONESIG,
	MONO_TABLE_EVENTMAP,
	MONO_TABLE_EVENT_POINTER,
	MONO_TABLE_EVENT,
	MONO_TABLE_PROPERTYMAP,
	MONO_TABLE_PROPERTY_POINTER,
	MONO_TABLE_PROPERTY,
	MONO_TABLE_METHODSEMANTICS,
	MONO_TABLE_METHODIMPL,
	MONO_TABLE_MODULEREF, /* 0x1a */
	MONO_TABLE_TYPESPEC,
	MONO_TABLE_IMPLMAP,
	MONO_TABLE_FIELDRVA,
	MONO_TABLE_UNUSED6,
	MONO_TABLE_UNUSED7,
	MONO_TABLE_ASSEMBLY, /* 0x20 */
	MONO_TABLE_ASSEMBLYPROCESSOR,
	MONO_TABLE_ASSEMBLYOS,
	MONO_TABLE_ASSEMBLYREF,
	MONO_TABLE_ASSEMBLYREFPROCESSOR,
	MONO_TABLE_ASSEMBLYREFOS,
	MONO_TABLE_FILE,
	MONO_TABLE_EXPORTEDTYPE,
	MONO_TABLE_MANIFESTRESOURCE,
	MONO_TABLE_NESTEDCLASS,
	MONO_TABLE_GENERICPARAM, /* 0x2a */
	MONO_TABLE_METHODSPEC,
	MONO_TABLE_GENERICPARAMCONSTRAINT
} MonoMetaTableEnum;


enum {
	MONO_TYPEDEF_FLAGS,
	MONO_TYPEDEF_NAME,
	MONO_TYPEDEF_NAMESPACE,
	MONO_TYPEDEF_EXTENDS,
	MONO_TYPEDEF_FIELD_LIST,
	MONO_TYPEDEF_METHOD_LIST,
	MONO_TYPEDEF_SIZE
};

enum {
	MONO_METHOD_RVA,
	MONO_METHOD_IMPLFLAGS,
	MONO_METHOD_FLAGS,
	MONO_METHOD_NAME,
	MONO_METHOD_SIGNATURE,
	MONO_METHOD_PARAMLIST,
	MONO_METHOD_SIZE
};


typedef enum {
	MONO_TOKEN_MODULE = 0x00000000,
	MONO_TOKEN_TYPE_REF = 0x01000000,
	MONO_TOKEN_TYPE_DEF = 0x02000000,
	MONO_TOKEN_FIELD_DEF = 0x04000000,
	MONO_TOKEN_METHOD_DEF = 0x06000000,
	MONO_TOKEN_PARAM_DEF = 0x08000000,
	MONO_TOKEN_INTERFACE_IMPL = 0x09000000,
	MONO_TOKEN_MEMBER_REF = 0x0a000000,
	MONO_TOKEN_CUSTOM_ATTRIBUTE = 0x0c000000,
	MONO_TOKEN_PERMISSION = 0x0e000000,
	MONO_TOKEN_SIGNATURE = 0x11000000,
	MONO_TOKEN_EVENT = 0x14000000,
	MONO_TOKEN_PROPERTY = 0x17000000,
	MONO_TOKEN_MODULE_REF = 0x1a000000,
	MONO_TOKEN_TYPE_SPEC = 0x1b000000,
	MONO_TOKEN_ASSEMBLY = 0x20000000,
	MONO_TOKEN_ASSEMBLY_REF = 0x23000000,
	MONO_TOKEN_FILE = 0x26000000,
	MONO_TOKEN_EXPORTED_TYPE = 0x27000000,
	MONO_TOKEN_MANIFEST_RESOURCE = 0x28000000,
	MONO_TOKEN_GENERIC_PARAM = 0x2a000000,
	MONO_TOKEN_METHOD_SPEC = 0x2b000000,

	/*
	 * These do not match metadata tables directly
	 */
	MONO_TOKEN_STRING = 0x70000000,
	MONO_TOKEN_NAME = 0x71000000,
	MONO_TOKEN_BASE_TYPE = 0x72000000
} MonoTokenType;

typedef void(__cdecl* GFunc)(void* data, void* user_data);

DO_API(MonoDomain*, mono_get_root_domain,(void));
DO_API(void*, mono_thread_attach,(MonoDomain* domain));
DO_API(void, mono_thread_detach,(MonoThread* monothread));
DO_API(void, mono_thread_cleanup,(void));
DO_API(void*, mono_object_get_class,(MonoObject* object));

DO_API(void, mono_domain_foreach,(GFunc func, void* user_data));

DO_API(int, mono_domain_set,(MonoDomain* domain, bool force));
DO_API(void*, mono_domain_get,());
DO_API(int, mono_assembly_foreach,(GFunc func, void* user_data));
DO_API(MonoImage*, mono_assembly_get_image,(MonoAssembly* assembly));
DO_API(void*, mono_assembly_open,(void* fname, int* status));
DO_API(void*, mono_image_get_assembly,(MonoImage* image));
DO_API(char*, mono_image_get_name,(MonoImage* image));
DO_API(void*, mono_image_open,(const char* fname, int* status));
DO_API(char*, mono_image_get_filename,(MonoImage* image));


DO_API(MonoTable*, mono_image_get_table_info,(MonoImage* image, int table_id));
DO_API(int, mono_table_info_get_rows,(MonoTable* tableinfo));
DO_API(int, mono_metadata_decode_row_col,(MonoTable* tableinfo, int idx, unsigned int col));
DO_API(char*, mono_metadata_string_heap,(MonoImage* image, UINT32 index));

DO_API(void*, mono_class_from_name_case,(MonoImage* image, const char* name_space, const char* name));
DO_API(MonoClass*, mono_class_from_name,(MonoImage* image, const char* name_space, const char* name));
DO_API(char*, mono_class_get_name,(MonoClass* klass));
DO_API(char*, mono_class_get_namespace,(MonoClass* klass));
DO_API(MonoClass*, mono_class_get,(MonoImage* image, UINT32 tokenindex));
DO_API(MonoClass*, mono_class_from_typeref,(MonoImage* image, UINT32 type_token));
DO_API(char*, mono_class_name_from_token,(MonoImage* image, UINT32 token));

DO_API(void*, mono_class_get_methods,(MonoClass* klass, void* iter));
DO_API(MethodInfo*, mono_class_get_method_from_name,(MonoClass* klass, const char* methodname, int paramcount));
DO_API(FieldInfo*, mono_class_get_fields,(MonoClass* klass, void* iter));
DO_API(void*, mono_class_get_parent,(MonoClass* klass));
DO_API(void*, mono_class_get_image,(MonoClass* klass));
DO_API(void*, mono_class_vtable,(MonoDomain* domain, MonoClass* klass));
DO_API(int, mono_class_instance_size,(MonoClass* klass));
DO_API(void*, mono_class_from_mono_type,(MonoType* type));
DO_API(void*, mono_class_get_element_class,(MonoClass* klass));
DO_API(int, mono_class_is_generic,(MonoClass* klass));



DO_API(int, mono_class_num_fields,(MonoClass* klass));
DO_API(int, mono_class_num_methods,(MonoClass* klass));

DO_API(char*, mono_field_get_name,(FieldInfo* field));
DO_API(MonoType*, mono_field_get_type,(FieldInfo* field));
DO_API(void*, mono_field_get_parent,(FieldInfo* field));
DO_API(int, mono_field_get_offset,(FieldInfo* field));

DO_API(char*, mono_type_get_name,(MonoType* type));
DO_API(int, mono_type_get_type,(MonoType* type));
DO_API(char*, mono_type_get_name_full,(MonoType* type, int format));
DO_API(int, mono_field_get_flags,(MonoType* type));


DO_API(FieldInfo*, mono_class_get_field_from_name, (MonoClass* klass, const char* name));

DO_API(char*, mono_method_get_name,(MethodInfo* method));
DO_API(void*, mono_compile_method,(MethodInfo* method));
DO_API(void, mono_free_method,(MethodInfo* method));

DO_API(void*, mono_jit_info_table_find,(MonoDomain* domain, void* addr));

DO_API(void*, mono_jit_info_get_method,(void* jitinfo));
DO_API(void*, mono_jit_info_get_code_start,(void* jitinfo));
DO_API(int, mono_jit_info_get_code_size,(void* jitinfo));

DO_API(int, mono_jit_exec,(MonoDomain* domain, MonoAssembly* assembly, int argc, char* argv[]));


DO_API(uint32_t, mono_method_get_flags,(MethodInfo* method, uint32_t* iflags));
DO_API(void*, mono_method_get_header,(MethodInfo* method));
DO_API(void*, mono_method_get_class,(MethodInfo* method));
DO_API(void*, mono_method_signature,(MethodInfo* method));
DO_API(void*, mono_method_get_param_names,(MethodInfo* method, const char** names));

DO_API(void*, mono_method_header_get_code,(MethodInfo* methodheader, UINT32* code_size, UINT32* max_stack));
DO_API(char*, mono_disasm_code,(void* dishelper, MethodInfo* method, void* ip, void* end));

DO_API(char*, mono_signature_get_desc,(void* signature, int include_namespace));
DO_API(MonoType*, mono_signature_get_params,(MonoMethodSignature* sig, void* iter));
DO_API(int, mono_signature_get_param_count,(void* signature));
DO_API(MonoType*, mono_signature_get_return_type,(void* signature));


DO_API(void*, mono_image_rva_map,(MonoImage* image, UINT32 addr));
DO_API(void*, mono_vtable_get_static_field_data,(void* vtable));


DO_API(void*, mono_method_desc_new,(const char* name, int include_namespace));
DO_API(void*, mono_method_desc_from_method,(MethodInfo* method));
DO_API(void, mono_method_desc_free,(void* desc));

DO_API(void*, mono_assembly_name_new,(const char* name));
DO_API(void*, mono_assembly_loaded,(void* aname));
DO_API(void*, mono_image_loaded,(void* aname));

DO_API(void*, mono_string_new,(MonoDomain* domain, const char* text));
DO_API(char*, mono_string_to_utf8,(void*));
DO_API(void*, mono_array_new,(MonoDomain* domain, void* eclass, uintptr_t n));
DO_API(void*, mono_object_to_string,(MonoObject* object, void** exc));
DO_API(void*, mono_object_new,(MonoDomain* domain, MonoClass* klass));


DO_API(void, mono_free,(void*));

DO_API(void*, mono_method_desc_search_in_image,(void* desc, MonoImage* image));
DO_API(void*, mono_runtime_invoke,(MethodInfo* method, MonoObject* obj, void** params, MonoObject** exc));
DO_API(void*, mono_runtime_invoke_array,(MethodInfo* method, MonoObject* obj, void* params, void** exc));
DO_API(void*, mono_runtime_object_init,(MonoObject* object));

DO_API(void*, mono_field_static_get_value,(void* vtable, FieldInfo* field, void* output));
DO_API(void*, mono_field_static_set_value,(void* vtable, FieldInfo* field, void* input));

DO_API(void*, mono_value_box,(MonoDomain* domain, MonoClass* klass, void* val));
DO_API(void*, mono_object_unbox,(MonoObject* obj));
DO_API(void*, mono_class_get_type,(MonoClass* klass));
DO_API(void*, mono_class_get_nesting_type,(MonoClass* klass));

DO_API(int, mono_runtime_is_shutting_down,(void));