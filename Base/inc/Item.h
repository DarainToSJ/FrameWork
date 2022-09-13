#ifndef _ITEM_H_
#define _ITEM_H_
#include <map>
#include <memory>
#include <string>
template <typename T>
class Item
{

public:
    explicit Item();
    ~Item();
    /**
     * @brief 清空表
     *
     */
    static void clear();
    /**
     * @brief  删除项根据ID
     *
     * @param id
     */

    static void erase(std::string id);
    /**
     * @brief 返回项个数
     *
     * @return size_t
     */
    static size_t size();
    /**
     * @brief 查找项
     *
     * @param id
     * @return std::shared_ptr<Item<T>>
     */
    static std::shared_ptr<Item<T>> at(std::string id);

    /**
     * @brief Create a Item object
     *
     * @return std::shared_ptr<Item<T>>
     */
    static std::shared_ptr<Item<T>> createItem();

    /**
     * @brief
     *
     * @return std::map<std::string, std::shared_ptr<Item<T>>>*
     */
    static std::map<std::string, std::shared_ptr<Item<T>>> *maps();

    /**
     * @brief  返回ID
     *
     * @return std::string
     */
    std::string ID();

    /**
     * @brief  返回数据项
     *
     * @return std::shared_ptr<T>
     */
    std::shared_ptr<T> data();

    /**
     * @brief Set the Data object
     *
     * @param ptr
     */
    void setData(std::shared_ptr<T> ptr);

private:
    std::string m_id;

    std::shared_ptr<T> m_data;

    static std::map<std::string, std::shared_ptr<Item<T>>> *m_items;
};

template <typename T>
std::map<std::string, std::shared_ptr<Item<T>>> *Item<T>::m_items = new std::map<std::string, std::shared_ptr<Item<T>>>;

template <typename T>
Item<T>::Item()
{
}
template <typename T>
Item<T>::~Item()
{
}
template <typename T>
std::string Item<T>::ID()
{
    return m_id;
}

template <typename T>
std::shared_ptr<T> Item<T>::data()
{
    return m_data;
}

template <typename T>
inline void Item<T>::setData(std::shared_ptr<T> ptr)
{
    m_data = std::move(ptr);
}

template <typename T>
inline std::shared_ptr<Item<T>> Item<T>::createItem()
{
    std::shared_ptr<Item<T>> item = std::make_shared<Item<T>>();
    std::shared_ptr<T> data = std::make_shared<T>();
    static_cast<Item<T> *>(item.get())->setData(data);
    std::pair<std::string, std::shared_ptr<Item<T>>> pair(static_cast<Item<T> *>(item->ID(), item);
    m_items->insert(pair);
    return item;
}
template <typename T>
inline size_t Item<T>::size()
{
    return m_items->size();
}
template <typename T>
inline std::map<std::string, std::shared_ptr<Item<T>>> *Item<T>::maps()
{
    return m_items;
}
template <typename T>
inline std::shared_ptr<Item<T>> Item<T>::at(std::string id)
{
    if (m_items->find(id) != m_items->end())
        return m_items->at(id);
    return nullptr;
}
template <typename T>
inline void Item<T>::clear()
{
    if (m_items->empty())
        return;
    m_items->clear();
}
template <typename T>
inline void Item<T>::erase(std::string id)
{
    if (m_items->find(id) != m_items->end())
    {
        m_items->erase(id);
    }
}

#endif // _ITEM_H_