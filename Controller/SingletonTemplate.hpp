#pragma once

namespace controllers{
    class Template {
        public:
            void test();



        private:
            static Template* P_SHARED_INSTANCE;

        private:
            Template();
            Template(Template const&);
            Template& operator = (const Template&);

        public:
            static Template* getInstance();
    };
}
