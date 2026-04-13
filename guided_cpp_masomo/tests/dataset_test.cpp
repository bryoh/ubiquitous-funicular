#include <gtest/gtest.h>

#include "guided_cpp/core/dataset.h"

TEST(DatasetTest, ReportsHeaderAndRowCounts) {
  guided_cpp::Dataset dataset(
      {"city", "population"},
      {
          {"Nairobi", "4397073"},
          {"Kampala", "1680600"},
      });

  EXPECT_EQ(dataset.column_count(), 2U);
  EXPECT_EQ(dataset.row_count(), 2U);
  EXPECT_FALSE(dataset.empty());
}

