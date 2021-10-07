#ifndef MYTABLE_H
#define MYTABLE_H

#include <QObject>
#include <QAbstractTableModel>


class MyTable : public QAbstractTableModel
{
    Q_OBJECT
private:
    enum columns{
        IP = 0,
        PORT,
        TIME,
        TYPE,
        SIZE,
        VERSION,
        PAYLOAD,
        CRC
     };
public:

    MyTable(QObject * pobj = 0);
    virtual ~MyTable();

public:
    QVariant data(const QModelIndex &index, int nRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int nRole);
    int rowCount(const QModelIndex &) const;
    int columnCount(const QModelIndex &) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;

    void appendData(QStringList);
    void setCell(QHash<int, QString>);

signals:

public slots:
private:
    int m_nRows;
    int m_nColumns;



    QHash<columns, QVariant> received_data;
    QList<QHash<columns, QVariant>> data_rows;
    QHash<int, QString> columns_names = {{IP, "IP"}, {PORT, "Port"}, {TIME, "Time"}, {TYPE, "Type"}, {SIZE, "Size"},
                                                 {VERSION, "Version"}, {PAYLOAD, "Payload"}, {CRC, "CRC"}};
};

#endif // MYTABLE_H
