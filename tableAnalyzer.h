//seungbin

#ifndef MULTIP4_TABLE_ANALYZER_H
#define MULTIP4_TABLE_ANALYZER_H

#include "ir/ir.h"
#include "ir/visitor.h"

namespace P4 {
  class ReferenceMap;
  class TypeMap;

} //namespace P4

namespace multip4 {

  class TableAnalyzer : public Inspector {
    public:
      TableAnalyzer(P4::ReferenceMap *refMap, P4::TypeMap *typeMap);

      bool preorder(const IR::PackageBlock *block) override;
      bool preorder(const IR::ControlBlock *block) override;
      bool preorder(const IR::P4Control *cont) override;
      bool preorder(const IR::BlockStatement *statement) override;
      bool preorder(const IR::IfStatement *statement) override;
      bool preorder(const IR::SwitchStatement *statement) override;
      bool preorder(const IR::MethodCallStatement *statement) override;
      bool preorder(const IR::AssignmentStatement *statement) override;
      bool preorder(const IR::ReturnStatement *) override;
      bool preorder(const IR::ExitStatement *) override;
      bool preorder(const IR::P4Table *table) override;
      bool preorder(const IR::ActionListElement *action) override;
      bool preorder(const IR::P4Action *action) override;
      bool preorder(const IR::KeyElement *key) override;

    private:
      P4::ReferenceMap *refMap; P4::TypeMap *typeMap;
  };

} //namespace multip4

#endif
