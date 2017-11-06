// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/ref_counted.h"

namespace base {

namespace subtle {

bool RefCountedThreadSafeBase::HasOneRef() const {
  return AtomicRefCountIsOne(
      &const_cast<RefCountedThreadSafeBase*>(this)->ref_count_);
}

RefCountedThreadSafeBase::RefCountedThreadSafeBase() : ref_count_(0) {
}

RefCountedThreadSafeBase::~RefCountedThreadSafeBase() {
}

void RefCountedThreadSafeBase::AddRef() const {
  AtomicRefCountInc(&ref_count_);
}

bool RefCountedThreadSafeBase::Release() const {
  if (!AtomicRefCountDec(&ref_count_)) {
    return true;
  }
  return false;
}

}  // namespace subtle

}  // namespace base
