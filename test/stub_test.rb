require "test/unit"

require "ycp"
require "ycp/mock"

class StubTest < Test::Unit::TestCase

  def test_simple_stub
    YCP::Mock.stub "Package::InstallAny",true
  end
end
