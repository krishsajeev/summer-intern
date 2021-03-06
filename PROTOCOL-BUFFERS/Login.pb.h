// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Login.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Login_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Login_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021002 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/map.h>  // IWYU pragma: export
#include <google/protobuf/map_entry.h>
#include <google/protobuf/map_field_inl.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Login_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Login_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Login_2eproto;
namespace USERS {
class User;
struct UserDefaultTypeInternal;
extern UserDefaultTypeInternal _User_default_instance_;
class Users;
struct UsersDefaultTypeInternal;
extern UsersDefaultTypeInternal _Users_default_instance_;
class Users_UsersEntry_DoNotUse;
struct Users_UsersEntry_DoNotUseDefaultTypeInternal;
extern Users_UsersEntry_DoNotUseDefaultTypeInternal _Users_UsersEntry_DoNotUse_default_instance_;
}  // namespace USERS
PROTOBUF_NAMESPACE_OPEN
template<> ::USERS::User* Arena::CreateMaybeMessage<::USERS::User>(Arena*);
template<> ::USERS::Users* Arena::CreateMaybeMessage<::USERS::Users>(Arena*);
template<> ::USERS::Users_UsersEntry_DoNotUse* Arena::CreateMaybeMessage<::USERS::Users_UsersEntry_DoNotUse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace USERS {

// ===================================================================

class User final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:USERS.User) */ {
 public:
  inline User() : User(nullptr) {}
  ~User() override;
  explicit PROTOBUF_CONSTEXPR User(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  User(const User& from);
  User(User&& from) noexcept
    : User() {
    *this = ::std::move(from);
  }

  inline User& operator=(const User& from) {
    CopyFrom(from);
    return *this;
  }
  inline User& operator=(User&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const User& default_instance() {
    return *internal_default_instance();
  }
  static inline const User* internal_default_instance() {
    return reinterpret_cast<const User*>(
               &_User_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(User& a, User& b) {
    a.Swap(&b);
  }
  inline void Swap(User* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(User* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  User* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<User>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const User& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const User& from) {
    User::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(User* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "USERS.User";
  }
  protected:
  explicit User(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
    kEmailFieldNumber = 2,
    kPasswdFieldNumber = 3,
    kLocationFieldNumber = 4,
    kUserIDFieldNumber = 5,
  };
  // optional string name = 1;
  bool has_name() const;
  private:
  bool _internal_has_name() const;
  public:
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // optional string email = 2;
  bool has_email() const;
  private:
  bool _internal_has_email() const;
  public:
  void clear_email();
  const std::string& email() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_email(ArgT0&& arg0, ArgT... args);
  std::string* mutable_email();
  PROTOBUF_NODISCARD std::string* release_email();
  void set_allocated_email(std::string* email);
  private:
  const std::string& _internal_email() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_email(const std::string& value);
  std::string* _internal_mutable_email();
  public:

  // optional string passwd = 3;
  bool has_passwd() const;
  private:
  bool _internal_has_passwd() const;
  public:
  void clear_passwd();
  const std::string& passwd() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_passwd(ArgT0&& arg0, ArgT... args);
  std::string* mutable_passwd();
  PROTOBUF_NODISCARD std::string* release_passwd();
  void set_allocated_passwd(std::string* passwd);
  private:
  const std::string& _internal_passwd() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_passwd(const std::string& value);
  std::string* _internal_mutable_passwd();
  public:

  // optional string location = 4;
  bool has_location() const;
  private:
  bool _internal_has_location() const;
  public:
  void clear_location();
  const std::string& location() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_location(ArgT0&& arg0, ArgT... args);
  std::string* mutable_location();
  PROTOBUF_NODISCARD std::string* release_location();
  void set_allocated_location(std::string* location);
  private:
  const std::string& _internal_location() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_location(const std::string& value);
  std::string* _internal_mutable_location();
  public:

  // optional string userID = 5;
  bool has_userid() const;
  private:
  bool _internal_has_userid() const;
  public:
  void clear_userid();
  const std::string& userid() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_userid(ArgT0&& arg0, ArgT... args);
  std::string* mutable_userid();
  PROTOBUF_NODISCARD std::string* release_userid();
  void set_allocated_userid(std::string* userid);
  private:
  const std::string& _internal_userid() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_userid(const std::string& value);
  std::string* _internal_mutable_userid();
  public:

  // @@protoc_insertion_point(class_scope:USERS.User)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr email_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr passwd_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr location_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr userid_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Login_2eproto;
};
// -------------------------------------------------------------------

class Users_UsersEntry_DoNotUse : public ::PROTOBUF_NAMESPACE_ID::internal::MapEntry<Users_UsersEntry_DoNotUse, 
    std::string, ::USERS::User,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE> {
public:
  typedef ::PROTOBUF_NAMESPACE_ID::internal::MapEntry<Users_UsersEntry_DoNotUse, 
    std::string, ::USERS::User,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE> SuperType;
  Users_UsersEntry_DoNotUse();
  explicit PROTOBUF_CONSTEXPR Users_UsersEntry_DoNotUse(
      ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);
  explicit Users_UsersEntry_DoNotUse(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  void MergeFrom(const Users_UsersEntry_DoNotUse& other);
  static const Users_UsersEntry_DoNotUse* internal_default_instance() { return reinterpret_cast<const Users_UsersEntry_DoNotUse*>(&_Users_UsersEntry_DoNotUse_default_instance_); }
  static bool ValidateKey(std::string* s) {
    return ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(s->data(), static_cast<int>(s->size()), ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::PARSE, "USERS.Users.UsersEntry.key");
 }
  static bool ValidateValue(void*) { return true; }
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  friend struct ::TableStruct_Login_2eproto;
};

// -------------------------------------------------------------------

class Users final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:USERS.Users) */ {
 public:
  inline Users() : Users(nullptr) {}
  ~Users() override;
  explicit PROTOBUF_CONSTEXPR Users(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Users(const Users& from);
  Users(Users&& from) noexcept
    : Users() {
    *this = ::std::move(from);
  }

  inline Users& operator=(const Users& from) {
    CopyFrom(from);
    return *this;
  }
  inline Users& operator=(Users&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Users& default_instance() {
    return *internal_default_instance();
  }
  static inline const Users* internal_default_instance() {
    return reinterpret_cast<const Users*>(
               &_Users_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(Users& a, Users& b) {
    a.Swap(&b);
  }
  inline void Swap(Users* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Users* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Users* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Users>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Users& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const Users& from) {
    Users::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Users* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "USERS.Users";
  }
  protected:
  explicit Users(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------


  // accessors -------------------------------------------------------

  enum : int {
    kUsersFieldNumber = 1,
  };
  // map<string, .USERS.User> users = 1;
  int users_size() const;
  private:
  int _internal_users_size() const;
  public:
  void clear_users();
  private:
  const ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::USERS::User >&
      _internal_users() const;
  ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::USERS::User >*
      _internal_mutable_users();
  public:
  const ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::USERS::User >&
      users() const;
  ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::USERS::User >*
      mutable_users();

  // @@protoc_insertion_point(class_scope:USERS.Users)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::MapField<
        Users_UsersEntry_DoNotUse,
        std::string, ::USERS::User,
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_STRING,
        ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE> users_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Login_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// User

// optional string name = 1;
inline bool User::_internal_has_name() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool User::has_name() const {
  return _internal_has_name();
}
inline void User::clear_name() {
  _impl_.name_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& User::name() const {
  // @@protoc_insertion_point(field_get:USERS.User.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void User::set_name(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000001u;
 _impl_.name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:USERS.User.name)
}
inline std::string* User::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:USERS.User.name)
  return _s;
}
inline const std::string& User::_internal_name() const {
  return _impl_.name_.Get();
}
inline void User::_internal_set_name(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.name_.Set(value, GetArenaForAllocation());
}
inline std::string* User::_internal_mutable_name() {
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.name_.Mutable(GetArenaForAllocation());
}
inline std::string* User::release_name() {
  // @@protoc_insertion_point(field_release:USERS.User.name)
  if (!_internal_has_name()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* p = _impl_.name_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.name_.IsDefault()) {
    _impl_.name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void User::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.name_.SetAllocated(name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.name_.IsDefault()) {
    _impl_.name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:USERS.User.name)
}

// optional string email = 2;
inline bool User::_internal_has_email() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool User::has_email() const {
  return _internal_has_email();
}
inline void User::clear_email() {
  _impl_.email_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline const std::string& User::email() const {
  // @@protoc_insertion_point(field_get:USERS.User.email)
  return _internal_email();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void User::set_email(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000002u;
 _impl_.email_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:USERS.User.email)
}
inline std::string* User::mutable_email() {
  std::string* _s = _internal_mutable_email();
  // @@protoc_insertion_point(field_mutable:USERS.User.email)
  return _s;
}
inline const std::string& User::_internal_email() const {
  return _impl_.email_.Get();
}
inline void User::_internal_set_email(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.email_.Set(value, GetArenaForAllocation());
}
inline std::string* User::_internal_mutable_email() {
  _impl_._has_bits_[0] |= 0x00000002u;
  return _impl_.email_.Mutable(GetArenaForAllocation());
}
inline std::string* User::release_email() {
  // @@protoc_insertion_point(field_release:USERS.User.email)
  if (!_internal_has_email()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000002u;
  auto* p = _impl_.email_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.email_.IsDefault()) {
    _impl_.email_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void User::set_allocated_email(std::string* email) {
  if (email != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  _impl_.email_.SetAllocated(email, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.email_.IsDefault()) {
    _impl_.email_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:USERS.User.email)
}

// optional string passwd = 3;
inline bool User::_internal_has_passwd() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool User::has_passwd() const {
  return _internal_has_passwd();
}
inline void User::clear_passwd() {
  _impl_.passwd_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline const std::string& User::passwd() const {
  // @@protoc_insertion_point(field_get:USERS.User.passwd)
  return _internal_passwd();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void User::set_passwd(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000004u;
 _impl_.passwd_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:USERS.User.passwd)
}
inline std::string* User::mutable_passwd() {
  std::string* _s = _internal_mutable_passwd();
  // @@protoc_insertion_point(field_mutable:USERS.User.passwd)
  return _s;
}
inline const std::string& User::_internal_passwd() const {
  return _impl_.passwd_.Get();
}
inline void User::_internal_set_passwd(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000004u;
  _impl_.passwd_.Set(value, GetArenaForAllocation());
}
inline std::string* User::_internal_mutable_passwd() {
  _impl_._has_bits_[0] |= 0x00000004u;
  return _impl_.passwd_.Mutable(GetArenaForAllocation());
}
inline std::string* User::release_passwd() {
  // @@protoc_insertion_point(field_release:USERS.User.passwd)
  if (!_internal_has_passwd()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000004u;
  auto* p = _impl_.passwd_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.passwd_.IsDefault()) {
    _impl_.passwd_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void User::set_allocated_passwd(std::string* passwd) {
  if (passwd != nullptr) {
    _impl_._has_bits_[0] |= 0x00000004u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000004u;
  }
  _impl_.passwd_.SetAllocated(passwd, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.passwd_.IsDefault()) {
    _impl_.passwd_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:USERS.User.passwd)
}

// optional string location = 4;
inline bool User::_internal_has_location() const {
  bool value = (_impl_._has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool User::has_location() const {
  return _internal_has_location();
}
inline void User::clear_location() {
  _impl_.location_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000008u;
}
inline const std::string& User::location() const {
  // @@protoc_insertion_point(field_get:USERS.User.location)
  return _internal_location();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void User::set_location(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000008u;
 _impl_.location_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:USERS.User.location)
}
inline std::string* User::mutable_location() {
  std::string* _s = _internal_mutable_location();
  // @@protoc_insertion_point(field_mutable:USERS.User.location)
  return _s;
}
inline const std::string& User::_internal_location() const {
  return _impl_.location_.Get();
}
inline void User::_internal_set_location(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000008u;
  _impl_.location_.Set(value, GetArenaForAllocation());
}
inline std::string* User::_internal_mutable_location() {
  _impl_._has_bits_[0] |= 0x00000008u;
  return _impl_.location_.Mutable(GetArenaForAllocation());
}
inline std::string* User::release_location() {
  // @@protoc_insertion_point(field_release:USERS.User.location)
  if (!_internal_has_location()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000008u;
  auto* p = _impl_.location_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.location_.IsDefault()) {
    _impl_.location_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void User::set_allocated_location(std::string* location) {
  if (location != nullptr) {
    _impl_._has_bits_[0] |= 0x00000008u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000008u;
  }
  _impl_.location_.SetAllocated(location, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.location_.IsDefault()) {
    _impl_.location_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:USERS.User.location)
}

// optional string userID = 5;
inline bool User::_internal_has_userid() const {
  bool value = (_impl_._has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool User::has_userid() const {
  return _internal_has_userid();
}
inline void User::clear_userid() {
  _impl_.userid_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000010u;
}
inline const std::string& User::userid() const {
  // @@protoc_insertion_point(field_get:USERS.User.userID)
  return _internal_userid();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void User::set_userid(ArgT0&& arg0, ArgT... args) {
 _impl_._has_bits_[0] |= 0x00000010u;
 _impl_.userid_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:USERS.User.userID)
}
inline std::string* User::mutable_userid() {
  std::string* _s = _internal_mutable_userid();
  // @@protoc_insertion_point(field_mutable:USERS.User.userID)
  return _s;
}
inline const std::string& User::_internal_userid() const {
  return _impl_.userid_.Get();
}
inline void User::_internal_set_userid(const std::string& value) {
  _impl_._has_bits_[0] |= 0x00000010u;
  _impl_.userid_.Set(value, GetArenaForAllocation());
}
inline std::string* User::_internal_mutable_userid() {
  _impl_._has_bits_[0] |= 0x00000010u;
  return _impl_.userid_.Mutable(GetArenaForAllocation());
}
inline std::string* User::release_userid() {
  // @@protoc_insertion_point(field_release:USERS.User.userID)
  if (!_internal_has_userid()) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000010u;
  auto* p = _impl_.userid_.Release();
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.userid_.IsDefault()) {
    _impl_.userid_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void User::set_allocated_userid(std::string* userid) {
  if (userid != nullptr) {
    _impl_._has_bits_[0] |= 0x00000010u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000010u;
  }
  _impl_.userid_.SetAllocated(userid, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.userid_.IsDefault()) {
    _impl_.userid_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:USERS.User.userID)
}

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// Users

// map<string, .USERS.User> users = 1;
inline int Users::_internal_users_size() const {
  return _impl_.users_.size();
}
inline int Users::users_size() const {
  return _internal_users_size();
}
inline void Users::clear_users() {
  _impl_.users_.Clear();
}
inline const ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::USERS::User >&
Users::_internal_users() const {
  return _impl_.users_.GetMap();
}
inline const ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::USERS::User >&
Users::users() const {
  // @@protoc_insertion_point(field_map:USERS.Users.users)
  return _internal_users();
}
inline ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::USERS::User >*
Users::_internal_mutable_users() {
  return _impl_.users_.MutableMap();
}
inline ::PROTOBUF_NAMESPACE_ID::Map< std::string, ::USERS::User >*
Users::mutable_users() {
  // @@protoc_insertion_point(field_mutable_map:USERS.Users.users)
  return _internal_mutable_users();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace USERS

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Login_2eproto
