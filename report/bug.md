4/27:
HashMapBUG：

- `clock`更新时读取的`activities`，所有值均未存在，为空，导致无法闹钟提醒！

已有信息：

- 在`get`方法中，table[i]不为空；而同一`i`，`put`方法下，table[i]为空
