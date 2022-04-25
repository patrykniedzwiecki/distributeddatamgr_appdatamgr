/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef DATASHARE_VALUES_BUCKET_H
#define DATASHARE_VALUES_BUCKET_H

#include <map>
#include <set>
#include <parcel.h>

#include "datashare_value_object.h"

namespace OHOS {
namespace DataShare {
class DataShareValuesBucket : public virtual OHOS::Parcelable {
public:
    DataShareValuesBucket();
    DataShareValuesBucket(std::map<std::string, DataShareValueObject> &valuesMap);
    ~DataShareValuesBucket();
    void PutString(const std::string &columnName, const std::string &value);
    void PutInt(const std::string &columnName, int value);
    void PutLong(const std::string &columnName, int64_t value);
    void PutDouble(const std::string &columnName, double value);
    void PutBool(const std::string &columnName, bool value);
    void PutBlob(const std::string &columnName, const std::vector<uint8_t> &value);
    void PutNull(const std::string &columnName);
    void Delete(const std::string &columnName);
    void Clear();
    int Size() const;
    bool IsEmpty() const;
    bool HasColumn(const std::string &columnName) const;
    bool GetObject(const std::string &columnName, DataShareValueObject &value) const;
    void GetAll(std::map<std::string, DataShareValueObject> &valuesMap) const;

    bool Marshalling(Parcel &parcel) const override;
    static DataShareValuesBucket *Unmarshalling(Parcel &parcel);
private:
    std::map<std::string, DataShareValueObject> valuesMap;
};
} // namespace DataShare
} // namespace OHOS
#endif
